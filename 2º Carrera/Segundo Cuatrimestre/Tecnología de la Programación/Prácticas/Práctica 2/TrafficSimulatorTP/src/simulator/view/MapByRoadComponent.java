package simulator.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.RenderingHints;
import java.io.File;
import java.io.IOException;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JComponent;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Junction;
import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;
import simulator.model.Vehicle;
import simulator.model.VehicleStatus;

public class MapByRoadComponent extends JComponent implements TrafficSimObserver{

	private static final long serialVersionUID = 1L;

	private static final int _JRADIUS = 10;

	private static final Color _BG_COLOR = Color.WHITE;
	private static final Color _JUNCTION_SRC_COLOR = Color.BLUE;
	private static final Color _GREEN_LIGHT_COLOR = Color.GREEN;
	private static final Color _RED_LIGHT_COLOR = Color.RED;
	private static final Color _ROAD_LABEL_COLOR = Color.BLACK;
	private static final Color _JUNCTION_LABEL_COLOR = new Color(200, 100, 0);
	

	private RoadMap _map;

	private Image _car;
	private Image _cloud;
	private Image _cont_0;
	private Image _cont_1;
	private Image _cont_2;
	private Image _cont_3;
	private Image _cont_4;
	private Image _cont_5;
	private Image _rain;
	private Image _sun;
	private Image _storm;
	private Image _wind;
	
	
	MapByRoadComponent(Controller ctrl) {
		setPreferredSize (new Dimension (300, 200));
		initGUI();
		ctrl.addObserver(this);
	}

	private void initGUI() {
		_car = loadImage("car.png");
		_cloud = loadImage("cloud.png");
		_cont_0 = loadImage("cont_0.png");
		_cont_1 = loadImage("cont_1.png");
		_cont_2 = loadImage("cont_2.png");
		_cont_3 = loadImage("cont_3.png");
		_cont_4 = loadImage("cont_4.png");
		_cont_5 = loadImage("cont_5.png");
		_rain = loadImage("rain.png");
		_sun = loadImage("sun.png");
		_storm = loadImage("storm.png");
		_wind = loadImage("wind.png");

		
	}

	public void paintComponent(Graphics graphics) {
		
		super.paintComponent(graphics);
		Graphics2D g = (Graphics2D) graphics;
		g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);

		setBackground( _BG_COLOR);
		
		g.clearRect(0, 0, getWidth(), getHeight());

		if (_map == null || _map.getRoads().size() == 0) {
			g.setColor(Color.red);
			g.drawString("No map yet!", getWidth() / 2 - 50, getHeight() / 2);
		} else {
			updatePrefferedSize();
			drawMap(g);
		}
	}

	private void drawMap(Graphics g) { 
		int i = 0;
		for (Road r:_map.getRoads()) {
	
			// the road goes from (x1,y) to (x2,y)
			int x1 =50;
			int x2=getWidth()-100;
			int y=(i+1)*50;

			//DRAW ROAD
			// choose a color for the circle (junction dest) depending on the traffic light
			Color juncDestColor = _RED_LIGHT_COLOR;
			int idx=r.getDest().getGreenLightIndex();
			if (idx != -1 && r.equals(r.getDest().getInRoads().get(idx))) {
				juncDestColor = _GREEN_LIGHT_COLOR;
			}

			// Draw line from (x1,y) to (x2,y)
			g.drawLine(x1, y, x2, y);
			// Draw circles at the beginning and end of the line
			g.setColor(_JUNCTION_LABEL_COLOR);
			g.drawString(r.getSrc().getId(), x1-2, y-7);
			g.drawString(r.getDest().getId(), x2-2, y-7);
			g.setColor(_JUNCTION_SRC_COLOR);
			g.fillOval(x1 - _JRADIUS / 2, y - _JRADIUS / 2, _JRADIUS, _JRADIUS);
			g.setColor(juncDestColor);
			g.fillOval(x2 - _JRADIUS / 2, y - _JRADIUS / 2, _JRADIUS, _JRADIUS);
			
			
			//DRAW VEHICLES
			y = y - 10; 
			for(Vehicle v: r.getVehicles()) {
				if (v.getStatus() != VehicleStatus.ARRIVED) {
					int x = x1 + (int) ((x2 - x1) * ((double) v.getLocalizacion() / (double) r.getLength()));
					int vLabelColor = (int) (25.0 * (10.0 - (double) v.getContClass())); //Car id color depending on contamination class
					g.setColor(new Color(0, vLabelColor, 0));
					g.drawImage(_car, x, y, 16, 16, this);
					g.drawString(v.getId(), x, y);
				}
			}
			
			//road ID
			g.setColor(_ROAD_LABEL_COLOR);
			g.drawString(r.getId(),x1-25, y);
			
			y = y-5;
			//DRAW WEATHER
			switch (r.getWeather() ) {
		      case SUNNY:
		    	  g.drawImage(_sun, x2 + 10, y, 32, 32, this);
		           break;
		      case CLOUDY:
		    	  g.drawImage(_cloud, x2 +10, y, 32, 32, this);
		           break;
		      case RAINY:
		    	  g.drawImage(_rain, x2 +10, y, 32, 32, this);
		           break;
		      case WINDY:
		    	  g.drawImage(_wind, x2 + 10, y, 32, 32, this);
		           break;
		      case STORM:
		    	  g.drawImage(_storm, x2 +10, y, 32, 32, this);
		           break;
		      }
			
			
			//DRAW CONTAMINATION
			int C = (int) Math.floor(Math.min((double) r.getTotalCO2()/(1.0 + (double) r.getCO2Limit()),1.0) / 0.19);
			switch ( C ) {
		      case 0:
		    	  g.drawImage(_cont_0, x2 +45, y, 32, 32, this);
		           break;
		      case 1:
		    	  g.drawImage(_cont_1, x2 +45, y, 32, 32, this);
		           break;
		      case 2:
		    	  g.drawImage(_cont_2, x2 + 45, y, 32, 32, this);
		           break;
		      case 3:
		    	  g.drawImage(_cont_3, x2 + 45, y, 32, 32, this);
		           break;
		      case 4:
		    	  g.drawImage(_cont_4, x2 + 45, y, 32, 32, this);
		           break;
		      case 5:
		    	  g.drawImage(_cont_5, x2 +45, y, 32, 32, this);
		           break;
		      }
			
			i++;
			
		}
	}
	

	// this method is used to update the preffered and actual size of the component,
	// so when we draw outside the visible area the scrollbars show up
	private void updatePrefferedSize() {
		int maxW = 200;
		int maxH = 200;
		for (Junction j : _map.getJunctions()) {
			maxW = Math.max(maxW, j.getX());
			maxH = Math.max(maxH, j.getY());
		}
		maxW += 20;
		maxH += 20;
		if (maxW > getWidth() || maxH > getHeight()) {
			setPreferredSize(new Dimension(maxW, maxH));
			setSize(new Dimension(maxW, maxH));
		} 
	}

	
	// loads an image from a file
	private Image loadImage(String img) {
		Image i = null;
		try {
			return ImageIO.read(new File("resources/icons/" + img));
		} catch (IOException e) {
		}
		return i;
	}

	public void update(RoadMap map) {
		_map = map;
		repaint();
	}

	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		update(map);
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		update(map);
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		update(map);
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		update(map);
	}

	@Override
	public void onError(String err) {
	}
	
}
