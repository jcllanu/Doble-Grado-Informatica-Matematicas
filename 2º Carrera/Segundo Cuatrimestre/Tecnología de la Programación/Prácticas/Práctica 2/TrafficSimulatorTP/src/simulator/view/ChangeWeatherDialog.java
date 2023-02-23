package simulator.view;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;

import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.Weather;

public class ChangeWeatherDialog extends JDialog {

	private int _status; 
	private JComboBox<Road> roads;
	private JComboBox<Weather> weather;
	private JSpinner ticks;
	private Weather[] weatherModelo= {Weather.SUNNY, Weather.CLOUDY, Weather.RAINY, Weather.WINDY, Weather.STORM};
	private DefaultComboBoxModel<Road> roadsModel;

	public ChangeWeatherDialog(Frame controlPanel) {
		super(controlPanel, true);					
		initGUI();
	}

	private void initGUI() {
		_status = 0;

		setTitle("Change Road Weather");
		JPanel panelPrincipal = new JPanel();
		panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
		setContentPane(panelPrincipal);
		
		//MENSAJE DE AYUDA
		JLabel mensajeAyuda1 = new JLabel("Schedule an event to change the weather of a road after");
		JLabel mensajeAyuda2 = new JLabel("a given number of simulation ticks from now.");
		
		mensajeAyuda1.setAlignmentX(CENTER_ALIGNMENT);
		mensajeAyuda2.setAlignmentX(CENTER_ALIGNMENT);

		panelPrincipal.add(mensajeAyuda1);
		panelPrincipal.add(mensajeAyuda2);
		panelPrincipal.add(Box.createRigidArea(new Dimension(0, 20)));
		
		
		//PANEL SELECCION CARRETERA, WEATHER Y TICKS
		JPanel panelOpciones = new JPanel();
		panelOpciones.setAlignmentX(CENTER_ALIGNMENT);
		panelPrincipal.add(panelOpciones);

		panelPrincipal.add(Box.createRigidArea(new Dimension(0, 20)));
		
		//PANEL BOTONES OK Y CANCELAR
		JPanel panelBotones = new JPanel();
		panelBotones.setAlignmentX(CENTER_ALIGNMENT);
		panelPrincipal.add(panelBotones);

		//SELECCION CARRETERA, WEATHER Y TICKS
		roadsModel = new DefaultComboBoxModel<>();
		roads = new JComboBox<>(roadsModel);
		weather=new JComboBox<>(weatherModelo);
		SpinnerModel sm = new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1);
		ticks = new JSpinner(sm);
		ticks.setPreferredSize(new Dimension(50, 50));
		
		panelOpciones.setLayout(new BoxLayout(panelOpciones, BoxLayout.X_AXIS));
		panelOpciones.add(new JLabel("  Road:  "));
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(roads);
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(new JLabel("  Weather:  "));
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(weather);
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(new JLabel("  Ticks:  "));
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(ticks);
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		
		
		//BOTON CANCELAR
		JButton cancelar = new JButton("Cancel");
		cancelar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 0; 
				ChangeWeatherDialog.this.setVisible(false);
			}
		});
		panelBotones.add(cancelar);

		
		//BOTON OK
		JButton ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (roadsModel.getSelectedItem() != null) {
					_status = 1;
					ChangeWeatherDialog.this.setVisible(false);
				}
			}
		});
		panelBotones.add(ok);

		setPreferredSize(new Dimension(500, 200));
		pack();
		setResizable(false);
		setVisible(false);
	}


	public int open(RoadMap map) {
		roadsModel.removeAllElements();
		for (Road r : map.getRoads())
			roadsModel.addElement(r);

		setLocation(getParent().getLocation().x + 250, getParent().getLocation().y + 250);
		setVisible(true); 				
		return _status;
	}

	Road getRoad() {
		return (Road) roads.getSelectedItem();
	}
	Weather getWeather() {
		return (Weather) weather.getSelectedItem();
	}
	int getTicks() {
		return (int) ticks.getValue();
	}

}
