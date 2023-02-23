package simulator.view;

import java.util.LinkedList;
import java.util.List;

import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Junction;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;

public class RoadsGreenTableModel extends AbstractTableModel implements TrafficSimObserver {
	Controller _ctrl;
	private String[] nombreColumnas = { "Time", "Roads with Green Light"};
	List<String> semaforosVerdes;
	int time;
	public RoadsGreenTableModel(Controller _ctrl) {
		this._ctrl=_ctrl;
		semaforosVerdes=new LinkedList<String>();
		initGUI();
	}
	private void initGUI() {
		_ctrl.addObserver(this);
	}
	@Override
	public int getRowCount() {
		return time;
	}

	@Override
	public int getColumnCount() {
		return nombreColumnas.length;
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		if(columnIndex==0)
			return rowIndex;
		if(rowIndex>=semaforosVerdes.size()) {
			return null;
		}else {
			return semaforosVerdes.get(rowIndex);
		}
		
	}
	public boolean isCellEditable(int row, int column) {
		return false;
	}
	
	@Override
	public String getColumnName(int col) {
		return nombreColumnas[col];
	}
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		String s="";
		for(Junction j: map.getJunctions()) {
			if(j.getGreenLightIndex()!=-1)
				s+=j.getInRoads().get(j.getGreenLightIndex()).getId()+" ";
		}
		semaforosVerdes.add(s);
		fireTableDataChanged();
		this.time=time;
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {

		
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		
	}

	@Override
	public void onError(String err) {
		// TODO Auto-generated method stub
		
	}


}
