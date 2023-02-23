package simulator.view;

import java.util.List;

import javax.swing.table.AbstractTableModel;


import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Junction;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;


public class JunctionsTableModel extends AbstractTableModel implements TrafficSimObserver{
	private Controller _ctrl;
	private List<Junction> junctions;
	private String[] nombreColumnas = { "Id", "Green", "Queues"};
	
	
	public JunctionsTableModel(Controller _ctrl) {
		this._ctrl=_ctrl;
		initGUI();
	}
	private void initGUI() {
		_ctrl.addObserver(this);
	}
	
	//MÉTODOS DE LA TABLA
	
	@Override
	public int getRowCount() {
		if(junctions==null) {
			return 0;
		}else {
			return junctions.size();
		}
	}
	
	@Override
	public int getColumnCount() {
		return nombreColumnas.length;
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		Object s = null;
		switch (columnIndex)
		{
		case 0:
			s= junctions.get(rowIndex).getId();
			break;
		case 1:{
			
			if(junctions.get(rowIndex).getGreenLightIndex()==-1) {
				s="NONE";
			}else {
				s=junctions.get(rowIndex).getInRoads().get(junctions.get(rowIndex).getGreenLightIndex());
			}
		}
			break;
		case 2:
			s=junctions.get(rowIndex).getListaColas();
			break;
		}
		return s;
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
		junctions=map.getJunctions();
		fireTableDataChanged();
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		junctions=map.getJunctions();
		fireTableDataChanged();
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		junctions=map.getJunctions();
		fireTableDataChanged();
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		junctions=map.getJunctions();
		fireTableDataChanged();
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		junctions=map.getJunctions();
		fireTableDataChanged();
	}

	@Override
	public void onError(String err) {
	}

}
