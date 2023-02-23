package simulator.view;

import java.util.List;

import javax.swing.table.AbstractTableModel;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Junction;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;
import simulator.model.Vehicle;
import simulator.model.VehicleStatus;

public class VehiclesTableModel extends AbstractTableModel implements TrafficSimObserver {
	private Controller _ctrl;
	private List<Vehicle> vehiculos;
	private String[] nombreColumnas = { "Id", "Location", "Itinerary", "CO2 Class", "Max. Speed", "Speed", "Total CO2", "Distance"};
	
	
	public VehiclesTableModel(Controller _ctrl) {
		this._ctrl=_ctrl;
		initGUI();
	}
	private void initGUI() {
		_ctrl.addObserver(this);
	}
	
	//MÉTODOS DE LA TABLA
	
	@Override
	public int getRowCount() {
		if(vehiculos==null) {
			return 0;
		}else {
			return vehiculos.size();
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
			s = vehiculos.get(rowIndex).getId();
			break;
		case 1:{
			VehicleStatus st= vehiculos.get(rowIndex).getStatus();
			if(st==VehicleStatus.ARRIVED) {
				s="Arrived";
			}else if(st==VehicleStatus.PENDING) {
				s="Pending";
			}else if(st==VehicleStatus.TRAVELING) {
				s=vehiculos.get(rowIndex).getRoad().getId()+":"+vehiculos.get(rowIndex).getLocalizacion();
			}else {
				s="Waiting:"+vehiculos.get(rowIndex).getCruceActual().getId();
			}
		}
			break;
		case 2:{
			String dev="[";
			for(Junction j: vehiculos.get(rowIndex).getItinerary()) {
				dev+=j.getId()+",";
			}
			dev+="]";
			s=dev;
		}
			break;
		case 3:
			s= vehiculos.get(rowIndex).getContClass();
			break;
		case 4:
			s= vehiculos.get(rowIndex).getMaxSpeed();
			break;
		case 5:
			s= vehiculos.get(rowIndex).getSpeed();
			break;
		case 6:
			s= vehiculos.get(rowIndex).getContamTotal();
			break;
		case 7:
			s= vehiculos.get(rowIndex).getDistance();
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
	
	//MÉTODOS OBSERVER
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		vehiculos=map.getVehicles();
		fireTableDataChanged();
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		vehiculos=map.getVehicles();
		fireTableDataChanged();
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		vehiculos=map.getVehicles();
		fireTableDataChanged();
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		vehiculos=map.getVehicles();
		fireTableDataChanged();
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		vehiculos=map.getVehicles();
		fireTableDataChanged();
	}

	@Override
	public void onError(String err) {	
	}

}
