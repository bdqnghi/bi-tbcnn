import akka.actor.ActorRef;

/**
 * Queue represents the line of bags and persons in this security station 
 * waiting to be processed by the various scanners. Incoming Persons are 
 * decoupled from their bags and sent to different queues. As space becomes
 * available in the bag and body scan, the first item from each respective 
 * queue is pulled and sent top the appropriate scanner to be checked.    
 * 
 * @author Chris
 * @author Carol
 * @author Andrew Lyne
 */
public class Queue extends AbstractActor {

	/**
	 * BaggageScanner to send bags to when ready. 
	 */
	final ActorRef baggageScanner; 
	
	/**
	 * BodyScanner to send Persons to when ready. 
	 */
	final ActorRef bodyScanner;
	
	/**
	 * Integer representing what number security station this queue belongs to.
	 */
	private final int stationNumber;
	
	/**
	 * Constructor for Queue. 
	 * 
	 * @param stationNumber - what number security station this queue 
	 * 		belongs to
	 * @param bodyScan - BodyScanner Actor to send People to
	 * @param bagScan - BaggageScanner Actor to send Baggage to
	 * @param terminal - Terminal Actor to send log messages to
	 */
	public Queue(int stationNumber, ActorRef bodyScan, ActorRef bagScan, ActorRef terminal){
		super(ActorFactory.QUEUE_SPACE, terminal);
		this.stationNumber = stationNumber;
		baggageScanner = bagScan;
		bodyScanner = bodyScan;
	}
	
	/**
	 * Redefinition of OnRecieve method from Actor. This class handles messages
	 * of EndDay and Person types.  
	 */
	@Override
	public void onReceive(Object message){
		/*
		 * If instance of Person, decouple the Person form their Baggage and 
		 * place each of these into the respective queues with recievePerson().
		 * Afterwards check to see if either the bag or body scan is ready to 
		 * receive input. If so, send the appropriate person to the appropriate
		 * open scanner. 
		 */
		if (message instanceof Person) {
			recievePerson( (Person)message );
		}
		/*
		 * If instance of EndDay message, check to see that both the 
		 * baggageQueue and bodyQueue are empty. If so, pass the message 
		 * along to the bodyScanner and BagScanner then shut self down. If 
		 * not, resend the EndOfDay message to self. This will delay shutting 
		 * down until all bags and people assigned to this queue have been 
		 * processed.  
		 */
		else if( message instanceof EndDay){
				printToTerminal("Queue " + stationNumber + 
						" received end of day message");

				getContext().stop();
		}
		/*
		 * All other messages are errors. Message printed here for debugging
		 * purposes.
		 */
		else{
			System.err.println("Queue recieved invalid message: " + 
					message.toString());
		}
	}

	/**
	 * Override of default stop function in actor. Prints a message to 
	 * Terminal actor before shutting down.  
	 */
	@Override
	public void postStop() {
		printToTerminal("Queue " + stationNumber + 
				" sent end of day message to bag scanner and body scanner");
		baggageScanner.tell(new EndDay());
		bodyScanner.tell(new EndDay());
		
	}
	
	/**
	 * Override of default start function in actor. Prints a message to 
	 * Terminal Actor out upon start up.  
	 */
	@Override
	public void preStart() {
		printToTerminal("Queue " + stationNumber + " Online");
	}
	
	/**
	 * Receives the passed Person argument into the security station. This 
	 * involves decoupling the Person from their Baggage and placing each into
	 * separate queues.   
	 * 
	 * @param p - Person to enter into station
	 * @return True if successful. False otherwise
	 */
	public void recievePerson(Person p){
		printToTerminal("Person " + p.getPersonId() + " enters queue " 
				+ stationNumber);
		printToTerminal("Person " + p.getPersonId() + "'s baggage sent to bagScan " 
				+ stationNumber);
		baggageScanner.tell(p.getBaggage());
		printToTerminal("Person " + p.getPersonId() + " sent to bodyScan " 
				+ stationNumber);
		bodyScanner.tell(p);
	}
	
	
	/**
	 * Accessor for which security station this queue belongs to. 
	 * @return - station number
	 */
	public int getStationNumber(){
		return stationNumber;
	}
}
