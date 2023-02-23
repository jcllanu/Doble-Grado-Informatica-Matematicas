package simulator.view;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JToolBar;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;

import simulator.launcher.Main;

import simulator.control.Controller;
import simulator.misc.Pair;
import simulator.model.Event;
import simulator.model.MostCrowdedStrategy;
import simulator.model.MoveAllStrategy;
import simulator.model.MoveFirstStrategy;
import simulator.model.NewCityRoadEvent;
import simulator.model.NewInterCityRoadEvent;
import simulator.model.NewJunctionEvent;
import simulator.model.NewVehicleEvent;
import simulator.model.RoadMap;
import simulator.model.RoundRobinStrategy;
import simulator.model.SetContClassEvent;
import simulator.model.SetWeatherEvent;
import simulator.model.TrafficSimObserver;
import simulator.model.Weather;

public class ControlPanel extends JPanel implements TrafficSimObserver{
	private RoadMap map;
	
	private boolean _stopped=true;
	private Controller _ctrl;
	private JButton cargarFicheros, cambiarContClass, cambiarWeather, nuevoVehiculo, nuevaCarretera, nuevoCruce, run, stop, exit;
	private JSpinner ticks;
	private JFileChooser fileChooser;
	private JToolBar barraHerramientas;
	int tiempoActual;
	
	public ControlPanel(Controller controlador){
		_ctrl=controlador;
		intGUI();
		_ctrl.addObserver(this);
	}
	
	
	private void intGUI() {
		
		//INICIALIZAR BOTONES
		cargarFicheros= new JButton();
		cambiarContClass= new JButton();
		cambiarWeather= new JButton();
		nuevoVehiculo=new JButton();
		nuevaCarretera=new JButton("Nueva Carretera");
		nuevoCruce=new JButton("Nuevo Cruce");
		run= new JButton();
		stop= new JButton();
		exit= new JButton();
		SpinnerModel sm = new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1);
		ticks = new JSpinner(sm);
		
		cargarFicheros.setPreferredSize(new Dimension(40, 40));
		cambiarContClass.setPreferredSize(new Dimension(40, 40));
		cambiarWeather.setPreferredSize(new Dimension(40, 40));
		nuevoVehiculo.setPreferredSize(new Dimension(40, 40));
		nuevaCarretera.setPreferredSize(new Dimension(40, 40));
		nuevoCruce.setPreferredSize(new Dimension(40, 40));
		run.setPreferredSize(new Dimension(40, 40));
		stop.setPreferredSize(new Dimension(40, 40));
		exit.setPreferredSize(new Dimension(40, 40));
		ticks.setPreferredSize(new Dimension(40, 40));
		
		//La JToolBar es el �nico componenete que a�adimos a ControlPanel (no necesitamos Layout para ControlPanel)
		barraHerramientas = new JToolBar();
		barraHerramientas.setPreferredSize(new Dimension(1000, 50));
		this.add(barraHerramientas);
		barraHerramientas.setLayout(new BoxLayout(barraHerramientas, BoxLayout.X_AXIS));
		
		//A�ADIR BOTONES
		barraHerramientas.add(cargarFicheros);
		barraHerramientas.addSeparator();
		barraHerramientas.add(cambiarContClass);
		barraHerramientas.add(cambiarWeather);
		barraHerramientas.add(nuevoVehiculo);
		barraHerramientas.add(nuevaCarretera);
		barraHerramientas.add(nuevoCruce);
		barraHerramientas.addSeparator();
		barraHerramientas.add(run);
		barraHerramientas.add(stop);
		barraHerramientas.add(ticks);
		barraHerramientas.add(Box.createGlue()); 
		barraHerramientas.add(exit);
		
		
		
		//BOT�N CARGAR FICHEROS
		cargarFicheros.setIcon(new ImageIcon("resources/icons/open.png"));
		fileChooser=new JFileChooser();
		cargarFicheros.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int ret = fileChooser.showOpenDialog(ControlPanel.this);
				
				if (ret == JFileChooser.APPROVE_OPTION) {
					_ctrl.reset();
					try {
						FileInputStream in = new FileInputStream(fileChooser.getSelectedFile());
						_ctrl.loadEvents(in);
					} catch (FileNotFoundException e1) {
						JOptionPane.showMessageDialog(ControlPanel.this,"Error al cargar el archivo: El archivo no existe");
					} catch (IllegalArgumentException e2) {
						JOptionPane.showMessageDialog(ControlPanel.this,"Error al cargar el archivo: "+e2.getMessage());
					}
				} 
			}
		});
		
		//BOT�N CAMBIAR CLASE DE CONTAMINACI�N
		cambiarContClass.setIcon(new ImageIcon("resources/icons/co2class.png"));
		cambiarContClass.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ChangeCO2ClassDialog dialog = new ChangeCO2ClassDialog((Frame) SwingUtilities.getWindowAncestor(ControlPanel.this));
				int status = dialog.open(map);
				if (status == 1) {
					List<Pair<String,Integer>> cs=new ArrayList<Pair<String,Integer>>();
					cs.add(new Pair<String, Integer>(dialog.getVehicle().toString(), dialog.getContClass()));
					_ctrl.addEvent(new SetContClassEvent(tiempoActual+dialog.getTicks(), cs));
				}
			}
		});
		
		//BOT�N CAMBIAR CONDICIONES ATMOSF�RICAS
		cambiarWeather.setIcon(new ImageIcon("resources/icons/weather.png"));
		cambiarWeather.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) { 
				ChangeWeatherDialog dialog = new ChangeWeatherDialog((Frame) SwingUtilities.getWindowAncestor(ControlPanel.this));
				int status = dialog.open(map);
				if (status == 1) {
					List<Pair<String,Weather>> ws=new ArrayList<Pair<String,Weather>>();
					ws.add(new Pair<String, Weather>(dialog.getRoad().toString(), dialog.getWeather()));
					_ctrl.addEvent(new SetWeatherEvent(tiempoActual+dialog.getTicks(), ws)); 											
				}
			}
		});
			
		//BOT�N NUEVO VEHICULO
		nuevoVehiculo.setIcon(new ImageIcon("resources/icons/car2.png"));
		nuevoVehiculo.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) { 
				NewVehicleDialog dialog = new NewVehicleDialog((Frame) SwingUtilities.getWindowAncestor(ControlPanel.this));
				int status = dialog.open(map);
				if (status == 1) {
					_ctrl.addEvent(new NewVehicleEvent(tiempoActual+dialog.getTicks(), dialog.getId(), dialog.getMaxSpeed(), 
							dialog.getContClass(), dialog.getItinerary())); 											
				}
			}
		});
		
		
		//BOT�N NUEVA CARRETERA
		nuevaCarretera.setIcon( new ImageIcon("resources/icons/road.png"));
		nuevaCarretera.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) { 
				NewRoadDialog dialog = new NewRoadDialog((Frame) SwingUtilities.getWindowAncestor(ControlPanel.this));
				int status = dialog.open(map);
				if (status == 1) {
					if(dialog.getRoadType().equals("CityRoad")) {
						_ctrl.addEvent(new NewCityRoadEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
								dialog.getSrc(), dialog.getDest(),  dialog.getLength(),dialog.getCO2() ,
								dialog.getMaxspeed(), dialog.getWeather()));
					}else {
						_ctrl.addEvent(new NewInterCityRoadEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
								dialog.getSrc(), dialog.getDest(),  dialog.getLength(),dialog.getCO2() ,
								dialog.getMaxspeed(), dialog.getWeather()));
					}
				}
			}
		});
				
		
		//BOT�N NUEVO CRUCE
		nuevoCruce.setIcon(new ImageIcon("resources/icons/junction.png"));
		nuevoCruce.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) { 
				NewJunctionDialog dialog = new NewJunctionDialog((Frame) SwingUtilities.getWindowAncestor(ControlPanel.this));
				int status = dialog.open(map);
				if (status == 1) {
					if(dialog.isDequeingAll()) {
						if(dialog.isSwitchingRobin()) {
							_ctrl.addEvent(new NewJunctionEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
									new RoundRobinStrategy(1), new MoveAllStrategy(),dialog.getXMio(),dialog.getYMio()));
						}else {
							_ctrl.addEvent(new NewJunctionEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
									new MostCrowdedStrategy(1), new MoveAllStrategy(),dialog.getXMio(),dialog.getYMio()));
						}
					}else {
						if(dialog.isSwitchingRobin()) {
							_ctrl.addEvent(new NewJunctionEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
									new RoundRobinStrategy(1), new MoveFirstStrategy(),dialog.getXMio(),dialog.getYMio()));
						}else {
							_ctrl.addEvent(new NewJunctionEvent(tiempoActual+dialog.getTicks(), dialog.getId(),
									new MostCrowdedStrategy(1), new MoveFirstStrategy(),dialog.getXMio(),dialog.getYMio()));
						}
					}											
				}
			}
		});
		
		
		//BOT�N RUN
		run.setIcon(new ImageIcon("resources/icons/run.png"));
		run.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				enableToolBar(false);
				_stopped=false;
				run_sim((int)ticks.getValue());
			}
		});
		
		//BOT�N STOP
		stop.setIcon(new ImageIcon("resources/icons/stop.png"));
		stop.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				stop();
				enableToolBar(true);
			}
		});
		
		//BOT�N EXIT
		exit.setIcon(new ImageIcon("resources/icons/exit.png"));
		exit.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int n = JOptionPane.showOptionDialog(ControlPanel.this,
						"Are sure you want to quit?", "Quit",
						JOptionPane.YES_NO_OPTION,
						JOptionPane.QUESTION_MESSAGE, null, null, null);
				if (n == 0) {
					System.out.println(Main.masificacion());
					System.exit(0);
				}
				
			}
		});
		
	}
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		this.map=map;
		tiempoActual=time;
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		this.map=map;
		tiempoActual=time;
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		this.map=map;
		tiempoActual=time;
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		this.map=map;
		tiempoActual=time;
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		this.map=map;
		tiempoActual=time;
	}

	@Override
	public void onError(String err) {
	}
	
	
	private void run_sim(int n) {
		if (n > 0 && !_stopped) {
			try {
				_ctrl.run(1);
			} catch (Exception e) {
				JOptionPane.showMessageDialog(ControlPanel.this,
						"Error al ejecutar: "+e.getMessage(), "ERROR",
						JOptionPane.ERROR_MESSAGE);
				_stopped = true;
				return;
			}
			SwingUtilities.invokeLater(new Runnable() {
				@Override
				public void run() {
					run_sim(n - 1);
				}
			});
		} else {
			enableToolBar(true);
			_stopped = true;
		}
	}
	private void stop() {
		_stopped = true;
	}
	
	void enableToolBar(boolean b){
		cargarFicheros.setEnabled(b);
		cambiarContClass.setEnabled(b);
		cambiarWeather.setEnabled(b);
		run.setEnabled(b);
		exit.setEnabled(b);
	}


}
