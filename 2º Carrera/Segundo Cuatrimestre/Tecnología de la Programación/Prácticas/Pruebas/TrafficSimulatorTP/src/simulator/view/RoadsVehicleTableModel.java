package simulator.view;

import java.util.List;

import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;
import simulator.model.Vehicle;

public class RoadsVehicleTableModel  extends AbstractTableModel implements TrafficSimObserver{
	private Controller _ctrl;
	private List<Road> roads;
	private String[] nombreColumnas = { "Id", "Length", "Weather", "Vehiculos", "Source", "Destination", "Fastest Vehicle"};
	
	
	public RoadsVehicleTableModel(Controller _ctrl) {
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
			{
				s="";
				for(Vehicle p: roads.get(rowIndex).getVehicles())
					s+=p.getId()+"  ";
			}
			break;
		case 4:
			s= roads.get(rowIndex).getSrc();
			break;
		case 5:
			s= roads.get(rowIndex).getDest();
			break;
		case 6:
			{
				if(roads.get(rowIndex).getVehicles().size()==0)
					s="No vehicles";
				else {
					Vehicle fastest=roads.get(rowIndex).getVehicles().get(0);
					for(Vehicle p: roads.get(rowIndex).getVehicles())
						if(p.getSpeed()>fastest.getSpeed())
							fastest=p;
					s=fastest.getId()+" ("+fastest.getSpeed()+"km/h)";
				}
				
					
			}
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
