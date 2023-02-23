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

public class NewJunctionDialog extends JDialog{

	private int _status; 
	private JSpinner ticks, x, y;
	private JTextField id;
	private JRadioButton robin, moveAll,moveFirst, mostCrowded;
	ButtonGroup grupoDeq,grupoSwitch;
	
	
	public NewJunctionDialog(Frame controlPanel) {
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
		JLabel mensajeAyuda1 = new JLabel("Schedule an event to add a new junction with certain settings after");
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

		//SELECCION CRUCE Y TICKS
			
		id = new JTextField();
		
		ticks = new JSpinner(new SpinnerNumberModel(1, 1, Integer.MAX_VALUE, 1));
		x = new JSpinner(new SpinnerNumberModel(50,50,400,50));
		y = new JSpinner(new SpinnerNumberModel(50,50,300,50));
	
		
		grupoDeq=new ButtonGroup();
		grupoSwitch=new ButtonGroup();
		
		robin=new JRadioButton("RoundRobin Strategy");
		mostCrowded=new JRadioButton("MostCrowded Strategy");
		moveAll=new JRadioButton("MoveAll Strategy");
		moveFirst=new JRadioButton("MoveFirst Strategy");
		
		grupoDeq.add(moveAll);
		grupoDeq.add(moveFirst);
		grupoDeq.setSelected(moveAll.getModel(), true);
		
		grupoSwitch.add(robin);
		grupoSwitch.add(mostCrowded);
		grupoSwitch.setSelected(robin.getModel(), true);
		
		
		panelOpciones.setLayout(new GridLayout(2,5,10,10));
		
		
		panelOpciones.add(new JLabel("Id:",SwingConstants.CENTER));
		panelOpciones.add(id);
		panelOpciones.add(new JLabel("X coordenate:",SwingConstants.CENTER));
		panelOpciones.add(x);
		JPanel panelD=new JPanel();
		panelOpciones.add(panelD);
		panelD.setLayout(new GridLayout(2,1,5,5));
		panelD.add(moveAll);
		panelD.add(moveFirst);
		
		
		panelOpciones.add(new JLabel("Ticks:",SwingConstants.CENTER));
		panelOpciones.add(ticks);
		panelOpciones.add(new JLabel("Y coordenate:",SwingConstants.CENTER));
		panelOpciones.add(y);
		JPanel panelS=new JPanel();
		panelOpciones.add(panelS);
		panelS.setLayout(new GridLayout(2,1,5,5));
		panelS.add(robin);
		panelS.add(mostCrowded);
		
		
		//BOTON CANCELAR
		JButton cancelar = new JButton("Cancel");
		cancelar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 0; 
				NewJunctionDialog.this.setVisible(false);
			}
		});
		panelBotones.add(cancelar);

		//BOTON OK
		JButton ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (id.getText().length()>0) {
					_status = 1;
					NewJunctionDialog.this.setVisible(false);
				}
			}
		});
		panelBotones.add(ok);

		pack();

		setVisible(false);
	}

	public int open(RoadMap map) {
		setLocation(getParent().getLocation().x + 250, getParent().getLocation().y + 250);
		setVisible(true); 				
		return _status;
	}

	

	public int getTicks() {
		return (int) ticks.getValue();
	}

	public String getId() {
		return id.getText();
	}

	public int getXMio() {
		return (int) x.getValue();
	}

	public int getYMio() {
		return (int) y.getValue();
	}

	public boolean isDequeingAll() {
		return moveAll.isSelected();
	}

	public boolean isSwitchingRobin() {
		return robin.isSelected();
	}
	
}
