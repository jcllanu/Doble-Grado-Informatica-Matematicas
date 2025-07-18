package simulator.launcher;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import javax.swing.SwingUtilities;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

import simulator.control.Controller;
import simulator.factories.Builder;
import simulator.factories.BuilderBasedFactory;
import simulator.factories.Factory;
import simulator.factories.MostCrowdedStrategyBuilder;
import simulator.factories.MoveAllStrategyBuilder;
import simulator.factories.MoveFirstStrategyBuilder;
import simulator.factories.NewCityRoadEventBuilder;
import simulator.factories.NewInterCityRoadEventBuilder;
import simulator.factories.NewJunctionEventBuilder;
import simulator.factories.NewRoundJunctionEventBuilder;
import simulator.factories.NewVehicleEventBuilder;
import simulator.factories.RotondaStrategyBuilder;
import simulator.factories.RoundRobinStrategyBuilder;
import simulator.factories.SetContClassEventBuilder;
import simulator.factories.SetWeatherEventBuilder;
import simulator.model.DequeuingStrategy;
import simulator.model.Event;
import simulator.model.LightSwitchingStrategy;
import simulator.model.TrafficSimulator;
import simulator.modelo.Crowdedness;
import simulator.view.MainWindow;

public class Main {

	private final static Integer _timeLimitDefaultValue = 10;
	private static String _inFile = null;
	private static String _outFile = null;
	private static Factory<Event> _eventsFactory = null;
	private static boolean modoGui = true;
	private static int ticks;
	
	private static void parseArgs(String[] args) {

		// define the valid command line options
		//
		Options cmdLineOptions = buildOptions();

		// parse the command line as provided in args
		//
		CommandLineParser parser = new DefaultParser();
		try {
			CommandLine line = parser.parse(cmdLineOptions, args);
			parseHelpOption(line, cmdLineOptions);
			parseInFileOption(line);
			parseOutFileOption(line);
			parseStepsOption(line);
			parseViewOption(line);
			// if there are some remaining arguments, then something wrong is
			// provided in the command line!
			//
			String[] remaining = line.getArgs();
			if (remaining.length > 0) {
				String error = "Illegal arguments:";
				for (String o : remaining)
					error += (" " + o);
				throw new ParseException(error);
			}

		} catch (ParseException e) {
			System.err.println(e.getLocalizedMessage());
			System.exit(1);
		}

	}

	

	private static Options buildOptions() {
		Options cmdLineOptions = new Options();

		cmdLineOptions.addOption(Option.builder("i").longOpt("input").hasArg().desc("Events input file").build());
		cmdLineOptions.addOption(
				Option.builder("o").longOpt("output").hasArg().desc("Output file, where reports are written.").build());
		cmdLineOptions.addOption(Option.builder("h").longOpt("help").desc("Print this message").build());
		cmdLineOptions.addOption(Option.builder("t").longOpt("ticks").hasArg().desc("Sets the number of ticks").build());
		cmdLineOptions.addOption(Option.builder("m").longOpt("mode").hasArg().desc("Selects the view mode").build());
		return cmdLineOptions;
	}
	private static void parseStepsOption(CommandLine line) {
		ticks=Integer.parseInt(line.getOptionValue("t",_timeLimitDefaultValue.toString()));
	}
	private static void parseHelpOption(CommandLine line, Options cmdLineOptions) {
		if (line.hasOption("h")) {
			HelpFormatter formatter = new HelpFormatter();
			formatter.printHelp(Main.class.getCanonicalName(), cmdLineOptions, true);
			System.exit(0);
		}
	}

	private static void parseInFileOption(CommandLine line) {
		_inFile = line.getOptionValue("i");
		
	}

	private static void parseOutFileOption(CommandLine line) throws ParseException {
		_outFile = line.getOptionValue("o");
	}
	
	private static void parseViewOption(CommandLine line) throws ParseException {
		if(line.getOptionValue("m")!=null && line.getOptionValue("m").equals("console")) {
			modoGui=false;
			if (_inFile == null) {
				throw new ParseException("An events file is missing");
			}
		}else {
			modoGui=true;
		}
	}
	private static void initFactories() {
		List<Builder<LightSwitchingStrategy>> lsbs = new ArrayList<>();
		lsbs.add( new RoundRobinStrategyBuilder() );
		lsbs.add( new MostCrowdedStrategyBuilder() );
		lsbs.add( new RotondaStrategyBuilder());
		
		Factory<LightSwitchingStrategy> lssFactory = new BuilderBasedFactory
		<>(lsbs);
		
		List<Builder<DequeuingStrategy>> dqbs = new ArrayList<>();
		dqbs.add( new MoveFirstStrategyBuilder() );
		dqbs.add( new MoveAllStrategyBuilder() );
		Factory<DequeuingStrategy> dqsFactory = new BuilderBasedFactory<>(
		dqbs);
		
		
		List<Builder<Event>> ebs = new ArrayList<>();
		ebs.add( new NewJunctionEventBuilder(lssFactory,dqsFactory) );
		ebs.add( new NewRoundJunctionEventBuilder() );
		ebs.add( new NewCityRoadEventBuilder() );
		ebs.add( new NewInterCityRoadEventBuilder() );
		ebs.add( new NewVehicleEventBuilder() );
		ebs.add( new SetContClassEventBuilder() );
		ebs.add( new SetWeatherEventBuilder() );
		
		Factory<Event> eventsFactory = new BuilderBasedFactory<>(ebs);
		_eventsFactory=eventsFactory;

	}

	private static void startBatchMode() throws IOException {
		Controller controller=new Controller(new TrafficSimulator(), _eventsFactory);
		OutputStream out;
		Crowdedness crowdedness=new Crowdedness(controller);
		if(_outFile==null){
			out=System.out;
		}else{
			out=new FileOutputStream(new File(_outFile));
		}
		FileInputStream in=new FileInputStream(_inFile);
		controller.loadEvents(in);
		controller.run(ticks,out);
		System.out.println(masificacion());
	}
	
	public static String masificacion() {
		
		return "[roads_info]"+"\n"+"crowdedness = "+Crowdedness.getCrowdedness();
	}



	private static void startGUIMode() throws IOException {
		Controller ctrl=new Controller(new TrafficSimulator(), _eventsFactory);
		Crowdedness crowdedness=new Crowdedness(ctrl);
		if(_inFile!=null) {
			FileInputStream in=new FileInputStream(_inFile);
			ctrl.loadEvents(in);
		}
		SwingUtilities.invokeLater( new Runnable() {
			@ Override
			public void run() {
				new MainWindow(ctrl);
			}
		});
		
		
	}
	
	private static void start(String[] args) throws IOException {
		initFactories();
		parseArgs(args);
		if(modoGui) {
			startGUIMode();
		}else {
			startBatchMode();
		}
		
	}

	



	// example command lines:
	//
	// -i resources/examples/ex1.json
	// -i resources/examples/ex1.json -t 300
	// -i resources/examples/ex1.json -o resources/tmp/ex1.out.json
	// --help

	public static void main(String[] args) {
		try {
			start(args);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
