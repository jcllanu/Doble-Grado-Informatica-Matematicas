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

public class MapByCarril extends JComponent implements TrafficSimObserver{

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
	
	
	MapByCarril(Controller ctrl) {
		setPreferredSize (new Dimension (300, 200));
		initGUI();
		ctrl.addObserver(this);
	}

	private void initGUI() {
		_car = loadImage("car_front.png");
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
		for(int i=0; i<_map.getRoads().size(); i++) {
			Road r=_map.getRoads().get(i);
			
			int x1=30+i*90;
			int x2=30+i*90+30;
			int x3=30+i*90+60;
		
			int y1=50;
			int y2=getHeight()-35;
			
			g.drawLine(x1, y1, x1, y2);
			drawDiscontinua(g,x2, y1, x2, y2);
			g.drawLine(x3, y1, x3, y2);
			g.drawLine(x1, y1, x3, y1);
			g.drawLine(x1, y2, x3, y2);

			Color colorVerde;
			Color colorRojo;
			int index=r.getDest().getGreenLightIndex();
			if(-1!=index&&r.getDest().getInRoads().get(index).equals(r)) {
				colorVerde=_GREEN_LIGHT_COLOR;
				colorRojo=new Color(100, 30, 22);
			}else {
				colorVerde=new Color(11, 83, 69);
				colorRojo=_RED_LIGHT_COLOR;
			}
			int xSem=(x2+x3)/2;
			g.fillRect(xSem- _JRADIUS/2-2,y1-35-_JRADIUS/2-2, _JRADIUS+4,2*_JRADIUS+9);
			g.setColor(colorVerde);
			g.fillOval(xSem- _JRADIUS/2, y1-35-_JRADIUS/2, _JRADIUS, _JRADIUS);
			g.setColor(colorRojo);
			g.fillOval(xSem- _JRADIUS/2, y1-20-_JRADIUS/2, _JRADIUS, _JRADIUS);
			
			g.setColor(Color.BLUE);
			int xCart=(x2+x1)/2;
			int ancho=r.getDest().getId().length()*6;
			g.fillRect(xCart-ancho/2 -2, y1-25-2, ancho+4, 15+4);
			g.setColor(Color.WHITE);
			g.drawString(r.getDest().getId(), 2+xCart-ancho/2, 2+y1-15);
			g.setColor(Color.BLACK);
			g.drawRect(xCart-ancho/2 -4, y1-25-4, ancho+8, 15+8);
		
			
			g.setColor(Color.BLUE);
			int xCart2=(x2+x1)/2;
			int ancho2=r.getSrc().getId().length()*6;
			g.fillRect(xCart2-ancho2/2 -2, y2+5, ancho2+4, 15+4);
			g.setColor(Color.WHITE);
			g.drawString(r.getSrc().getId(), 2+xCart2-ancho2/2, 2+y2+15);
			g.setColor(Color.BLACK);
			g.drawRect(xCart2-ancho/2 -4, y2+5-2, ancho2+8, 15+8);
			
			
			g.setColor(Color.BLUE);
			int yAux=(y2+y1)/2;
			int ancho3=r.getId().length()*6;
			g.fillRect(x1-ancho3 - 12, yAux-5, ancho3+10, 15);
			g.setColor(Color.WHITE);
			g.drawString(r.getId(), x1-ancho3-5, yAux+7);
			g.setColor(Color.BLACK);
			g.drawRect(x1-ancho3 - 14, yAux-7, ancho3+14, 19);
			
			
			for(int j=0; j<r.getVehicles().size();j++) {
				Vehicle v=r.getVehicles().get(j);
				
				int xVeh= (j%2==0?(x1+x2)/2:(x3+x2)/2);
				if (v.getStatus() != VehicleStatus.ARRIVED) {
					int y=y2+(y1-y2)*v.getLocalizacion()/r.getLength();
					int vLabelColor = (int) (25.0 * (10.0 - (double) v.getContClass())); //Car id color depending on contamination class
					g.setColor(new Color(0, vLabelColor, 0));
					g.fillOval( xVeh-10, y-10, 20, 20);
					g.drawImage(_car, xVeh-8, y-8, 16, 16, this);
					g.drawString(v.getId(), xVeh-v.getId().length()*3, y-10);
				}
			}
			g.setColor(Color.BLACK);
		}
		
		for(int i=0; i<_map.getRoads().size(); i++) {
			Road r=_map.getRoads().get(i);
			int x=getWidth()-100;
			int y=(i+1)*50;
			
			g.setColor(Color.BLACK);
			g.drawString(r.getId(), x, y);
			
			switch (r.getWeather() ) {
		      case SUNNY:
		    	  g.drawImage(_sun, x + 10, y, 32, 32, this);
		           break;
		      case CLOUDY:
		    	  g.drawImage(_cloud, x +10, y, 32, 32, this);
		           break;
		      case RAINY:
		    	  g.drawImage(_rain, x +10, y, 32, 32, this);
		           break;
		      case WINDY:
		    	  g.drawImage(_wind, x + 10, y, 32, 32, this);
		           break;
		      case STORM:
		    	  g.drawImage(_storm, x +10, y, 32, 32, this);
		           break;
		      }
			
			
			//DRAW CONTAMINATION
			int C = (int) Math.floor(Math.min((double) r.getTotalCO2()/(1.0 + (double) r.getCO2Limit()),1.0) / 0.19);
			switch ( C ) {
		      case 0:
		    	  g.drawImage(_cont_0, x +45, y, 32, 32, this);
		           break;
		      case 1:
		    	  g.drawImage(_cont_1, x +45, y, 32, 32, this);
		           break;
		      case 2:
		    	  g.drawImage(_cont_2, x + 45, y, 32, 32, this);
		           break;
		      case 3:
		    	  g.drawImage(_cont_3, x + 45, y, 32, 32, this);
		           break;
		      case 4:
		    	  g.drawImage(_cont_4, x + 45, y, 32, 32, this);
		           break;
		      case 5:
		    	  g.drawImage(_cont_5, x +45, y, 32, 32, this);
		           break;
		      }
		}
		
		
	}
	


	private void drawDiscontinua(Graphics g, int x, int y1, int x1, int y2) {
		for(int i=y1; i<y2;i+=10) {
			g.drawLine(x, i, x, i+5);
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
