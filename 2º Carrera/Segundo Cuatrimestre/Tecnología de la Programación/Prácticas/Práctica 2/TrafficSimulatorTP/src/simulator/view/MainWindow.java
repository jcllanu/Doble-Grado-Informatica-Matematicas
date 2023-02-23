package simulator.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;

import simulator.control.Controller;

public class MainWindow extends JFrame {
	
	private Controller _ctrl;
	
	public MainWindow(Controller ctrl) {
		super("Traffic Simulator");
		_ctrl = ctrl;
		initGUI();
	}
	
	private void initGUI() {
		JPanel mainPanel = new JPanel(new BorderLayout());
		this.setContentPane(mainPanel);
		
		//CONTROL PANEL
		mainPanel.add(new ControlPanel(_ctrl), BorderLayout.PAGE_START);
		
		//STATUS BAR
		mainPanel.add(new StatusBar(_ctrl),BorderLayout.PAGE_END);
		
		
		JPanel viewsPanel = new JPanel(new GridLayout(1, 2));
		mainPanel.add(viewsPanel, BorderLayout.CENTER);
		
		JPanel tablesPanel = new JPanel();
		tablesPanel.setLayout(new BoxLayout(tablesPanel, BoxLayout.Y_AXIS));
		viewsPanel.add(tablesPanel);
		
		JPanel mapsPanel = new JPanel();
		mapsPanel.setLayout(new BoxLayout(mapsPanel, BoxLayout.Y_AXIS));
		viewsPanel.add(mapsPanel);
		
		// TABLES
		JPanel eventsView =createViewPanel(new JTable(new EventsTableModel(_ctrl)), "Events");
		eventsView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(eventsView);
		
		JPanel vehiclesView =createViewPanel(new JTable(new VehiclesTableModel(_ctrl)), "Vehicles");
		vehiclesView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(vehiclesView);
		
		JPanel roadsView =createViewPanel(new JTable(new RoadsTableModel(_ctrl)), "Roads");
		roadsView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(roadsView);		
		
		JPanel junctionsView =createViewPanel(new JTable(new JunctionsTableModel(_ctrl)), "Junctions");
		junctionsView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(junctionsView);
		
		
		// MAPS
		JPanel mapView = createViewPanel(new MapComponent(_ctrl), "Map");
		mapsPanel.add(mapView);
		
		JPanel mapByRoadView = createViewPanel(new MapByRoadComponent(_ctrl), "Map by roads");
		mapsPanel.add(mapByRoadView);
		
		
		this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		//Con esta l�nea hacemos que se cierre la GUI al pulsar la x
		//this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		this.pack();
		this.setVisible(true);
		
		}
	
	private JPanel createViewPanel(JComponent c, String title) {
		Border _defaultBorder = BorderFactory.createLineBorder(Color.black, 1);
		JPanel p = new JPanel( new BorderLayout() );
		p.setBorder(BorderFactory.createTitledBorder(_defaultBorder,
				title, TitledBorder.LEFT, TitledBorder.TOP));
		p.add(new JScrollPane(c));
		return p;
		
	}

}
