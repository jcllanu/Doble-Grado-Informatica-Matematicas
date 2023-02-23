package simulator.view;

import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;

public class StatusBar extends JPanel implements TrafficSimObserver{
	private Controller _ctrl;
	
	private JLabel mensaje;
	private JLabel tiempo;
	public StatusBar(Controller _ctrl) {
		this._ctrl=_ctrl;
		initGUI();
		
	}
	private void initGUI() {
		this.setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
		tiempo=new JLabel("  Time:  0");
		mensaje=new JLabel("");
		this.add(tiempo);
		this.add(new JLabel("                               "));
		this.add(mensaje);
		_ctrl.addObserver(this);
	}
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		tiempo.setText("  Time:  "+time);
		mensaje.setText("");
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		tiempo.setText("  Time:  "+time);
		
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		tiempo.setText("  Time:  "+time);
		mensaje.setText("Event added ("+e.toString()+")");
		
		
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		tiempo.setText("  Time:  "+time);
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		tiempo.setText("  Time:  "+time);
	}

	@Override
	public void onError(String err) {
		mensaje.setText(err);
	}

}
