package simulator.view;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.ButtonModel;
import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingConstants;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import simulator.model.Junction;
import simulator.model.RoadMap;
import simulator.model.Vehicle;
import simulator.model.Weather;

public class NewRoadDialog extends JDialog{

	private int _status; 
	private JComboBox<Weather> weather;
	private Weather[] weatherModelo= {Weather.SUNNY, Weather.CLOUDY, Weather.RAINY, Weather.WINDY, Weather.STORM};
	private JSpinner ticks, maxSpeed, length, co2Limit;
	private JTextField id, source, destination;
	private JList<String> junctions;
	private JRadioButton city, intercity;
	DefaultListModel<String> modeloJunctions;
	ButtonGroup grupo;
	
	
	public NewRoadDialog(Frame controlPanel) {
		super(controlPanel, true);					
		initGUI();
	}

	private void initGUI() {
		_status = 0;

		setTitle("Add New Road");
		JPanel panelPrincipal = new JPanel();
		panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
		setContentPane(panelPrincipal);

		//MENSAJE DE AYUDA
		JLabel mensajeAyuda1 = new JLabel("Schedule an event to add a new road with certain settings after");
		JLabel mensajeAyuda2 = new JLabel("a given number of simulation ticks from now.");
		
		mensajeAyuda1.setAlignmentX(CENTER_ALIGNMENT);
		mensajeAyuda2.setAlignmentX(CENTER_ALIGNMENT);
		
		panelPrincipal.add(mensajeAyuda1);
		panelPrincipal.add(mensajeAyuda2);
		panelPrincipal.add(Box.createRigidArea(new Dimension(0, 20)));

		//PANEL SELECCION VEHICULO, CONTCLASS Y TICKS
		JPanel panelOpciones = new JPanel();
		panelOpciones.setAlignmentX(CENTER_ALIGNMENT);
		panelPrincipal.add(panelOpciones);

		panelPrincipal.add(Box.createRigidArea(new Dimension(0, 20)));

		//PANEL BOTONES OK Y CANCELAR
		JPanel panelBotones = new JPanel();
		panelBotones.setAlignmentX(CENTER_ALIGNMENT);
		panelPrincipal.add(panelBotones);

		//SELECCION CARRETERA Y TICKS
			
		id = new JTextField();
		source= new JTextField();
		source.setEditable(false);
		destination= new JTextField();
		destination.setEditable(false);
		
		
		ticks = new JSpinner(new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1));
		maxSpeed = new JSpinner(new SpinnerNumberModel(50,10,200,10));
		length = new JSpinner(new SpinnerNumberModel(500,500,50000,500));
		co2Limit = new JSpinner(new SpinnerNumberModel(500,500,50000,500));
		
		grupo=new ButtonGroup();
		city=new JRadioButton("CityRoad");
		intercity=new JRadioButton("InterCityRoad");
		grupo.add(city);
		grupo.add(intercity);;
		grupo.setSelected(city.getModel(), true);
		
		weather=new JComboBox<>(weatherModelo);
		
		modeloJunctions=new DefaultListModel<String>();
		junctions=new JList<String>(modeloJunctions);
		
		
		junctions.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		
		JButton annadirSource= new JButton("Origen");
		annadirSource.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(junctions.isSelectionEmpty())
					JOptionPane.showMessageDialog(NewRoadDialog.this, "Tienes que seleccionar un cruce que añadir");
				else
					source.setText(junctions.getSelectedValue());
			}
			
		});
		
		JButton annadirDest= new JButton("Destino");
		
		annadirDest.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(junctions.isSelectionEmpty())
					JOptionPane.showMessageDialog(NewRoadDialog.this, "Tienes que seleccionar un cruce que añadir");
				else
					destination.setText(junctions.getSelectedValue());
			}
			
		});
		
		panelOpciones.setLayout(new GridLayout(2,1,10,10));
		
		JPanel panelSuperior=new JPanel();
		panelOpciones.add(panelSuperior);
		panelSuperior.setLayout(new GridLayout(1,13,5,5));
		
		JPanel panelInferior=new JPanel();
		panelOpciones.add(panelInferior);
		panelInferior.setLayout(new GridLayout(1,12,5,5));
		
		panelSuperior.add(new JLabel("Id:",SwingConstants.CENTER));
		panelSuperior.add(id);
		panelSuperior.add(Box.createRigidArea(new Dimension(20,20)));
		panelSuperior.add(annadirSource);
		panelSuperior.add(source);
		panelSuperior.add(Box.createRigidArea(new Dimension(20,20)));
		panelSuperior.add(annadirDest);
		panelSuperior.add(destination);
		panelSuperior.add(new JLabel("Cruces:",SwingConstants.CENTER));
		panelSuperior.add(junctions);
		panelSuperior.add(Box.createRigidArea(new Dimension(20,20)));
		panelSuperior.add(new JLabel("Length:",SwingConstants.CENTER));
		panelSuperior.add(length);
		
		panelInferior.add(new JLabel("CO2 Limit:",SwingConstants.CENTER));
		panelInferior.add(co2Limit);
		panelInferior.add(Box.createRigidArea(new Dimension(20,20)));
		panelInferior.add(new JLabel("Max. Speed:",SwingConstants.CENTER));
		panelInferior.add(maxSpeed);
		panelInferior.add(Box.createRigidArea(new Dimension(20,20)));
		panelInferior.add(new JLabel("Weather:",SwingConstants.CENTER));
		panelInferior.add(weather);
		panelInferior.add(Box.createRigidArea(new Dimension(20,20)));
		JPanel panelRadiobuttons=new JPanel();
		panelInferior.add(panelRadiobuttons);
		panelRadiobuttons.setLayout(new GridLayout(2,1,5,5));
		panelRadiobuttons.add(city);
		panelRadiobuttons.add(intercity);
		
		panelInferior.add(new JLabel("Ticks:",SwingConstants.CENTER));
		panelInferior.add(ticks);
		
		
		//BOTON CANCELAR
		JButton cancelar = new JButton("Cancel");
		cancelar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 0; 
				NewRoadDialog.this.setVisible(false);
			}
		});
		panelBotones.add(cancelar);

		//BOTON OK
		JButton ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (destination.getText().length()>0 &&source.getText().length()>0 && id.getText().length()>0) {
					_status = 1;
					NewRoadDialog.this.setVisible(false);
				}
			}
		});
		panelBotones.add(ok);

		this.setSize(1200,500);

		setVisible(false);
	}

	public int open(RoadMap map) {
		modeloJunctions.removeAllElements();
		for (Junction v :map.getJunctions())
			modeloJunctions.addElement(v.getId());

		setLocation(getParent().getLocation().x + 250, getParent().getLocation().y + 250);
		setVisible(true); 				
		return _status;
	}

	public String getRoadType() {
		return (city.isSelected()?"CityRoad":"InterCityRoad");
	}

	public int getTicks() {
		return (int) ticks.getValue();
	}

	public String getId() {
		return id.getText();
	}

	public String getSrc() {
		return source.getText();
	}
	public String getDest() {
		return destination.getText();
	}

	public int getLength() {
		return (int) length.getValue();
	}

	public int getCO2() {
		return (int) co2Limit.getValue();
	}

	public int getMaxspeed() {
		return (int) maxSpeed.getValue();
	}

	public Weather getWeather() {
		return (Weather) weather.getSelectedItem();
	}
	
}
