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

import simulator.control.Controller;
import simulator.model.RoadMap;
import simulator.model.Vehicle;

public class ChangeCO2ClassDialog extends JDialog{

	private int _status; 
	private JComboBox<Vehicle> vehiculos;
	private JComboBox<Integer> contClass;
	private JSpinner ticks;
	private Integer[] contClassModelo= {0,1,2,3,4,5,6,7,8,9,10};
	private DefaultComboBoxModel<Vehicle> vehiculosModel;

	public ChangeCO2ClassDialog(Frame controlPanel) {
		super(controlPanel, true);					
		initGUI();
	}

	private void initGUI() {
		_status = 0;

		setTitle("Change CO2 Class");
		JPanel panelPrincipal = new JPanel();
		panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
		setContentPane(panelPrincipal);

		//MENSAJE DE AYUDA
		JLabel mensajeAyuda1 = new JLabel("Schedule an event to change the CO2 class of a vehicle after");
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
		vehiculosModel = new DefaultComboBoxModel<>();
		vehiculos = new JComboBox<>(vehiculosModel);
		contClass=new JComboBox<>(contClassModelo);
		SpinnerModel sm = new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1);
		ticks = new JSpinner(sm);
		ticks.setPreferredSize(new Dimension(50, 50));
		
		
		panelOpciones.setLayout(new BoxLayout(panelOpciones, BoxLayout.X_AXIS));
		JLabel l1= new JLabel("  Vehicle:  ");
		panelOpciones.add(l1);
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(vehiculos);
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(new JLabel("  CO2 Class:  "));
		panelPrincipal.add(Box.createRigidArea(new Dimension(5, 20)));
		panelOpciones.add(contClass);
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
				ChangeCO2ClassDialog.this.setVisible(false);
			}
		});
		panelBotones.add(cancelar);

		//BOTON OK
		JButton ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (vehiculosModel.getSelectedItem() != null) {
					_status = 1;
					ChangeCO2ClassDialog.this.setVisible(false);
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
		vehiculosModel.removeAllElements();
		for (Vehicle v :map.getVehicles())
			vehiculosModel.addElement(v);

		setLocation(getParent().getLocation().x + 250, getParent().getLocation().y + 250);
		setVisible(true); 				
		return _status;
	}

	Vehicle getVehicle() {
		return (Vehicle) vehiculosModel.getSelectedItem();
	}
	Integer getContClass() {
		return (Integer) contClass.getSelectedItem();
	}
	int getTicks() {
		return (int) ticks.getValue();
	}
}
