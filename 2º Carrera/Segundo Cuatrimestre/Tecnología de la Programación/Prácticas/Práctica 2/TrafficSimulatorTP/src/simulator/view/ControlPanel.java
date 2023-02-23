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

import simulator.control.Controller;
import simulator.misc.Pair;
import simulator.model.Event;
import simulator.model.RoadMap;
import simulator.model.SetContClassEvent;
import simulator.model.SetWeatherEvent;
import simulator.model.TrafficSimObserver;
import simulator.model.Weather;

public class ControlPanel extends JPanel implements TrafficSimObserver{
	private RoadMap map;
	
	private boolean _stopped=true;
	private Controller _ctrl;
	private JButton cargarFicheros,cambiarContClass,cambiarWeather, run, stop, exit;
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
		run= new JButton();
		stop= new JButton();
		exit= new JButton();
		SpinnerModel sm = new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1);
		ticks = new JSpinner(sm);
		
		cargarFicheros.setPreferredSize(new Dimension(40, 40));
		cambiarContClass.setPreferredSize(new Dimension(40, 40));
		cambiarWeather.setPreferredSize(new Dimension(40, 40));
		run.setPreferredSize(new Dimension(40, 40));
		stop.setPreferredSize(new Dimension(40, 40));
		exit.setPreferredSize(new Dimension(40, 40));
		ticks.setPreferredSize(new Dimension(40, 40));
		
		//La JToolBar es el único componenete que añadimos a ControlPanel (no necesitamos Layout para ControlPanel)
		barraHerramientas = new JToolBar();
		barraHerramientas.setPreferredSize(new Dimension(1000, 50));
		this.add(barraHerramientas);
		barraHerramientas.setLayout(new BoxLayout(barraHerramientas, BoxLayout.X_AXIS));
		
		//AÑADIR BOTONES
		barraHerramientas.add(cargarFicheros);
		barraHerramientas.addSeparator();
		barraHerramientas.add(cambiarContClass);
		barraHerramientas.add(cambiarWeather);
		barraHerramientas.addSeparator();
		barraHerramientas.add(run);
		barraHerramientas.add(stop);
		barraHerramientas.add(ticks);
		barraHerramientas.add(Box.createGlue()); 
		barraHerramientas.add(exit);
		
		
		
		//BOTÓN CARGAR FICHEROS
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
		
		//BOTÓN CAMBIAR CLASE DE CONTAMINACIÓN
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
		
		//BOTÓN CAMBIAR CONDICIONES ATMOSFÉRICAS
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
				
		//BOTÓN RUN
		run.setIcon(new ImageIcon("resources/icons/run.png"));
		run.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				enableToolBar(false);
				_stopped=false;
				run_sim((int)ticks.getValue());
			}
		});
		
		//BOTÓN STOP
		stop.setIcon(new ImageIcon("resources/icons/stop.png"));
		stop.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				stop();
				enableToolBar(true);
			}
		});
		
		//BOTÓN EXIT
		exit.setIcon(new ImageIcon("resources/icons/exit.png"));
		exit.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int n = JOptionPane.showOptionDialog(ControlPanel.this,
						"Are sure you want to quit?", "Quit",
						JOptionPane.YES_NO_OPTION,
						JOptionPane.QUESTION_MESSAGE, null, null, null);
				if (n == 0) {
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
