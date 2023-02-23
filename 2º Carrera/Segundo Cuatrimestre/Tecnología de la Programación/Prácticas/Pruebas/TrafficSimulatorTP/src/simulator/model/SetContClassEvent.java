package simulator.model;

import java.util.List;

import simulator.misc.Pair;

public class SetContClassEvent extends Event{
	private List<Pair<String,Integer>> cs;
	public SetContClassEvent(int time, List<Pair<String,Integer>> cs) {
		super(time);
		this.cs=cs;
		if(cs==null) {
			throw new IllegalArgumentException("cs no debe ser null");
		}
			
	}
	void execute(RoadMap map) {
		for(Pair<String,Integer> w: cs) {
			if(map.getVehicle(w.getFirst())==null) {
				throw new IllegalArgumentException("cs no tiene un formato correcto");
			}else {
				map.getVehicle(w.getFirst()).setContaminationClass(w.getSecond());
			}
		}
	}
	@Override
	public String toString() {
		String dev= "Change Weather: [";
		for(int i=0; i<cs.size();i++) {
			dev+="("+cs.get(i).getFirst()+","+cs.get(i).getSecond()+")";
			if(i!=cs.size()-1) {
				dev+=",";
			}
		}
		dev+="]";
		return dev;
	}

}
