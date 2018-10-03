package org.dementhium.content.misc;

import org.dementhium.model.Mob;
import org.dementhium.model.Projectile;
import org.dementhium.model.World;
import org.dementhium.model.combat.Interaction;
import org.dementhium.model.misc.DamageManager.DamageHit;
import org.dementhium.model.misc.DamageManager.DamageType;
import org.dementhium.model.player.Player;
import org.dementhium.tickable.Tick;
import org.dementhium.util.Misc;

/**
 * Used for DFS spec ect.
 * @author Canownueasy
 */
@SuppressWarnings("unused")
public final class DFS {

	private final Player owner;
	
	public final int hit = 0;
	
	public DFS(Player owner) {
		this.owner = owner;
		World.getWorld().submit(new Tick(2) {
			
			public void execute() {
				if (delay > 0) delay--;
			}

			
			
			
			
		});
	}
	private int charges = 0, delay = 0;

	public void setCharges(int charges) {
		this.charges = charges;
	}

	public void setDelay(int delay) {
		this.delay = delay;
	}

	public int getCharges() {
		return charges;
	}

	public int getDelay() {
		return delay;
	}
	
	//sec let me just add 1 quikc thing then u can continue. soz
	
	public void spec() {
		if (owner == null) return;
		

		
		
		
		
		if (!owner.isOnline() || owner.isDead()) return;
		final Mob last = owner.getCombatExecutor().getLastAttacker();
		if (last == null) {
			owner.sendMessage("You must be in combat to operate your dragonfire shield.");
			return;
		}
		if (last.isDead()) return;
			/*	if (charges < 1) {
			owner.sendMessage("You do not have enough charges to use the Dragonfire shield's effect.");
			return;
		}*/
		if (delay > 0) {
			owner.sendMessage("Let your dragonfire shield cool down for " + delay + " more seconds.");
			return;
		}

		/*charges--;*/
		delay += 180;
		
		owner.turnTemporarilyTo(last);

		owner.getCombatExecutor().setAttackDelay(owner.getCombatExecutor().getAttackDelay() + 5);
		last.getCombatExecutor().setAttackDelay(owner.getCombatExecutor().getAttackDelay() - 1);
		owner.getCombatExecutor().setSpellDelay(owner.getCombatExecutor().getAttackDelay());
		last.getCombatExecutor().setSpellDelay(last.getCombatExecutor().getSpellDelay());
		owner.animate(6696);
		owner.graphics(1165, 0 << 16);
		World.getWorld().submit(new Tick(2) {
			@Override
			public void execute() {
				Projectile.create(owner, last, 142, 136, 48, 42, 8);
				World.getWorld().submit(new Tick(2) {
					@Override
					public void execute() {
						last.graphics(1167, 100 << 16);
						if (!last.isAnimating()) last.animate(last.getDefenceAnimation());
						this.stop();
					}
				});
				World.getWorld().submit(new Tick(3) {
					@Override
					public void execute() {
						
						 last.getDamageManager().damage(last, (int) (Misc.random(286)), -1, DamageType.RED_DAMAGE);
						
						this.stop();
					}
				});
				this.stop();
			}
		});
	}
}

