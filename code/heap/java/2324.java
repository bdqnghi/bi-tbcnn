package de.seerhein_lab.jic.vm;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicLong;

import org.apache.bcel.generic.Type;

import de.seerhein_lab.jic.analyzer.ClassHelper;

/**
 * Class whose instances represent heaps. A heap contains objects, some of which
 * have been published, as well as two special objects, i.e. the 'this' instance
 * and the external object. The higher layers can create objects only through a
 * heap.
 */
public class Heap {
	public static AtomicLong count = new AtomicLong();
	private final Map<UUID, HeapObject> objects = new HashMap<UUID, HeapObject>();

	private final UUID thisID;

	/**
	 * Constructor. Creates the 'this' instance.
	 */
	public Heap(String type) {
		HeapObject thisObject = new UnknownObject(this, ClassHelper.isImmutable(type), type);
		thisID = thisObject.getId();
		objects.put(thisID, thisObject);

		count.incrementAndGet();
	}

	public Heap() {
		this("java.lang.Object");
	}

	/**
	 * Copy-Constructor.
	 * 
	 * @param original
	 *            The heap to copy from.
	 */
	public Heap(Heap original) {
		for (UUID id : original.objects.keySet()) {
			objects.put(id, original.objects.get(id).copy(this));
		}

		thisID = original.thisID;
		count.incrementAndGet();
	}

	/**
	 * Returns the object with the given ID <code>id</code>. If <code>id</code>
	 * is null, the null is returned; if the object has been published, the
	 * external object is returned.
	 * 
	 * @param id
	 *            the ID of the object to be returned
	 * @return the object with the given ID,
	 */
	protected HeapObject get(UUID id) {
		if (id == null)
			return null;

		if (objects.containsKey(id))
			return objects.get(id);

		throw new NoSuchElementException("HeapObject not found in this Heap");
	}

	/**
	 * Gets this heap's 'this' instance
	 * 
	 * @return this heap's 'this' instance
	 */
	public UnknownObject getThisInstance() {
		return (UnknownObject) get(thisID);
	}

	/**
	 * Creates a new class instance and registers it in the heap.
	 * 
	 * @param immutable
	 *            The immutablility of the class instance
	 * 
	 * @return The newly created class instance.
	 */
	public ClassInstance newClassInstance(boolean immutable, String type) {
		ClassInstance object = new ClassInstance(this, immutable, type);
		objects.put(object.getId(), object);
		return object;
	}

	public ClassInstance newClassInstanceOfDynamicType(Type type) {
		return newClassInstance(ClassHelper.isImmutable(type), type.toString());
	}

	public ClassInstance newClassInstanceOfStaticType(Type type) {
		return newClassInstance(ClassHelper.isImmutableAndFinal(type), type.toString());
	}

	public ClassInstance newClassInstanceOfDynamicType(String type) {
		return newClassInstance(ClassHelper.isImmutable(type), type);
	}

	public UnknownObject newUnknownObject(boolean immutable, String type) {
		UnknownObject object = new UnknownObject(this, immutable, type);
		objects.put(object.getId(), object);
		return object;
	}

	public UnknownObject newUnknownObjectOfStaticType(Type type) {
		return newUnknownObject(ClassHelper.isImmutableAndFinal(type), type.toString());
	}

	/**
	 * Creates a new array and registers it in the heap.
	 * 
	 * @return The newly created array.
	 */
	public Array newArray(String type) {
		Array object = new Array(this, type);
		objects.put(object.getId(), object);
		return object;
	}

	/**
	 * Publishes all objects that belong to this complex object. The published
	 * objects are replaced by the external object in all referred links,
	 * removed from this heap's set of regular objects, and added to the list of
	 * this heap's published objects.
	 * 
	 * @param obj
	 *            The entry to this complex object to be published
	 */
	public void publish(HeapObject obj) {
		if (obj == null)
			return;

		// if (obj.equals(getThisInstance()))
		// // don't publish this in order not to cover further bugs
		// return;

		for (HeapObject o : obj.getClosure()) {
			if (!(o instanceof UnknownObject))
				objects.put(o.getId(), new UnknownObject(o, this));
		}
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((objects == null) ? 0 : objects.hashCode());
		result = prime * result + ((thisID == null) ? 0 : thisID.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Heap other = (Heap) obj;
		if (objects == null) {
			if (other.objects != null)
				return false;
		} else if (!objects.equals(other.objects))
			return false;
		if (thisID == null) {
			if (other.thisID != null)
				return false;
		} else if (!thisID.equals(other.thisID))
			return false;
		return true;
	}

	public Collection<HeapObject> getObjects() {
		return objects.values();
	}

}
