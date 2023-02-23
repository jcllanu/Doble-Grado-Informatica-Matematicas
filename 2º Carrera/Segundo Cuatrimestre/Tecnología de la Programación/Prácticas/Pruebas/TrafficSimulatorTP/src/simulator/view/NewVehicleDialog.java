package simulator.view;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import simulator.model.Junction;
import simulator.model.RoadMap;
import simulator.model.Vehicle;

public class NewVehicleDialog extends JDialog{

	private int _status; 
	private JComboBox<Integer> contClass;
	private JSpinner ticks, maxSpeed;
	private Integer[] contClassModelo= {0,1,2,3,4,5,6,7,8,9,10};
	private JTextField id;
	private JList<String> itinerario;
	DefaultListModel<String> modeloLista;
	private JList<String> junctions;
	DefaultListModel<String> modeloJunctions;
	
	
	public NewVehicleDialog(Frame controlPanel) {
		super(controlPanel, true);					
		initGUI();
	}

	private void initGUI() {
		_status = 0;

		setTitle("Add New Vehicle");
		JPanel panelPrincipal = new JPanel();
		panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
		setContentPane(panelPrincipal);

		//MENSAJE DE AYUDA
		JLabel mensajeAyuda1 = new JLabel("Schedule an event to add a new vehicle with certain settings after");
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

		//SELECCION VEHICULO, CONTCLASS Y TICKS
		
		contClass=new JComboBox<>(contClassModelo);
		SpinnerModel sm = new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1);
		ticks = new JSpinner(sm);
		maxSpeed = new JSpinner(new SpinnerNumberModel(50,10,200,10));
		id = new JTextField();
		modeloLista=new DefaultListModel<String>();
		modeloJunctions=new DefaultListModel<String>();
		itinerario=new JList<String>(modeloLista);
		junctions=new JList<String>(modeloJunctions);
		
		
		maxSpeed.setPreferredSize(new Dimension(50, 50));
		ticks.setPreferredSize(new Dimension(50, 50));
		id.setPreferredSize(new Dimension(50, 50));
		
		
		
		
		junctions.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		
		JButton annadir= new JButton("Añadir junnction a itinerario");
		
		annadir.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(junctions.isSelectionEmpty())
					JOptionPane.showMessageDialog(NewVehicleDialog.this, "Tienes que seleccionar un crude que añadir");
				else
					modeloLista.addElement(junctions.getSelectedValue());
			}
			
		});
		
		panelOpciones.setLayout(new BoxLayout(panelOpciones, BoxLayout.X_AXIS));
		
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(new JLabel("Vehicle Id:"));
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(id);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(new JLabel("Max. Speed:"));
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(maxSpeed);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(new JLabel("Cont. Class:"));
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(contClass);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(new JLabel("Itinerary:"));
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(itinerario);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(annadir);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(junctions);
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(new JLabel("  Ticks:  "));
		panelOpciones.add(Box.createRigidArea(new Dimension(5, 5)));
		panelOpciones.add(ticks);
		
		
		
		
		//BOTON CANCELAR
		JButton cancelar = new JButton("Cancel");
		cancelar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 0; 
				NewVehicleDialog.this.setVisible(false);
			}
		});
		panelBotones.add(cancelar);

		//BOTON OK
		JButton ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (modeloLista.size()>=2 && id.getText().length()>0) {
					_status = 1;
					NewVehicleDialog.this.setVisible(false);
				}
			}
		});
		panelBotones.add(ok);

		setSize(800, 250);
		

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

	Integer getContClass() {
		return (Integer) contClass.getSelectedItem();
	}
	int getTicks() {
		return (int) ticks.getValue();
	}

	public String getId() {
		return id.getText();
	}

	public int getMaxSpeed() {
		return (int) maxSpeed.getValue();
	}

	public List<String> getItinerary() {
		List<String> l= new ArrayList<String>();
		for(int i=0; i<modeloLista.size(); i++)
			l.add(modeloLista.get(i));
		
		return l;
	}

}
