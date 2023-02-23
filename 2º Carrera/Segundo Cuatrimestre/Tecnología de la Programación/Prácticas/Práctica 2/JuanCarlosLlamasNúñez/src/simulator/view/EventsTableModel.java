package simulator.view;

import java.util.List;

import javax.swing.table.AbstractTableModel;


import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;

public class EventsTableModel extends AbstractTableModel implements TrafficSimObserver {
	private Controller _ctrl;
	private List<Event> eventos;
	private String[] nombreColumnas = { "Time", "Description"};
	
	
	public EventsTableModel(Controller _ctrl) {
		this._ctrl=_ctrl;
		initGUI();
	}
	private void initGUI() {
		_ctrl.addObserver(this);
	}
	
	//MÉTODOS DE LA TABLA
	@Override
	public int getRowCount() {
		if(eventos==null) {
			return 0;
		}else {
			return eventos.size();
		}
	}

	@Override
	public int getColumnCount() {
		return nombreColumnas.length;
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		Object s = null;
		if(columnIndex == 0) {
			s=eventos.get(rowIndex).getTime();
		}else if(columnIndex == 1) {
			s=eventos.get(rowIndex).toString();
		}
		return s;
	}
	
	@Override
	public boolean isCellEditable(int row, int column) {
		return false;
	}
	@Override
	public String getColumnName(int col) {
		return nombreColumnas[col];
	}
	
	//MÉTODOS OBSERVER
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		eventos=events;
		fireTableDataChanged();
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		eventos=events;
		fireTableDataChanged();
		
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		eventos=events;
		fireTableDataChanged();
		
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		eventos=events;
		fireTableDataChanged();
		
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		eventos=events;
		fireTableDataChanged();
	}

	@Override
	public void onError(String err) {	
	}

}
