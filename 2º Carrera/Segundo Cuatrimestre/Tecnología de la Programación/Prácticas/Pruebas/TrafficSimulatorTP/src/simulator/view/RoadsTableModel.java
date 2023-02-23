package simulator.view;

import java.util.List;

import javax.swing.table.AbstractTableModel;
import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;


public class RoadsTableModel  extends AbstractTableModel implements TrafficSimObserver  {
	private Controller _ctrl;
	private List<Road> roads;
	private String[] nombreColumnas = { "Id", "Length", "Weather", "Max. Speed", "Speed Limit", "Total CO2", "CO2 Limit"};
	
	
	public RoadsTableModel(Controller _ctrl) {
		this._ctrl=_ctrl;
		initGUI();
	}
	private void initGUI() {
		_ctrl.addObserver(this);
	}
	
	@Override
	public int getRowCount() {
		if(roads==null) {
			return 0;
		}else {
			return roads.size();
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
			s= roads.get(rowIndex).getId();
			break;
		case 1:
			s= roads.get(rowIndex).getLength();
			break;
		case 2:
			s= roads.get(rowIndex).getWeather();
			break;
		case 3:
			s= roads.get(rowIndex).getMaxSpeed();
			break;
		case 4:
			s= roads.get(rowIndex).getSpeedLimit();
			break;
		case 5:
			s= roads.get(rowIndex).getTotalCO2();
			break;
		case 6:
			s= roads.get(rowIndex).getCO2Limit();
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
		roads=map.getRoads();
		fireTableDataChanged();
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		roads=map.getRoads();
		fireTableDataChanged();
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		roads=map.getRoads();
		fireTableDataChanged();
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		roads=map.getRoads();
		fireTableDataChanged();
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		roads=map.getRoads();
		fireTableDataChanged();
	}

	@Override
	public void onError(String err) {	
	}


}
