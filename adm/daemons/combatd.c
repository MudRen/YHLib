// combatd.c
// Update by Doing for HELL

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

// �����������(/combat/)��˵��
// PKS��ɱ���������Ŀ
// MKS��ɱ����NPC��Ŀ(���ﲻ����)
// WPK������ɱ����ҵĴ���
// WPK_NOTGOOD������ɱ��������(shen < 500)��ҵĴ���
// WPK_BAD��    ����ɱ����а��(shen <-500)��ҵĴ���
// WPK_NOTBAD�� ����ɱ����а��(shen >-500)��ҵĴ���
// WPK_GOOD��   ����ɱ��������(shen > 500)��ҵĴ���
// DPS������������ҵĴ���
// DPS_NOTGOOD���������η�����(shen < 500)��ҵĴ���
// DPS_BAD��    �������ε�а��(shen <-500)��ҵĴ���
// DPS_NOTBAD�� �������η�а��(shen >-500)��ҵĴ���
// DPS_GOOD��   �������ε�����(shen > 500)��ҵĴ���
// dietimes��   �����Ĵ���

// combat/today��¼(mapping)
// which_day: ����(ʵ��ʱ��������)
// id       : n, ��������ĳ��ID�Ĵ���

#define MAX_KILL_TIMES_PERMAN           2
#define MAX_KILL_TIMES_PERDAY           8

// �������(random(my_exp) > EXP_LIMIT���򲻼Ӿ���)
#define	EXP_LIMIT	200000

string *guard_msg = ({
        append_color(CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR, CYN),
        append_color(CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR, CYN),
        append_color(CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR, CYN),
        append_color(CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR, CYN),
        append_color(CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR, CYN),
});

string *catch_hunt_msg = ({
        append_color(HIW "$N��$n������������ۺ죬���̴���������\n" NOR, HIW),
        append_color(HIW "$N����$nһ����ȣ����ֱ�������\n" NOR, HIW),
        append_color(HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR, HIW),
        append_color(HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR, HIW) });

string *winner_msg = ({
        append_color(CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR, CYN),
        append_color(CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR, CYN),
        append_color(CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR, CYN),
        append_color(CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR, CYN),
        append_color(CYN "\n$n������˼�����˵�����ⳡ�����������ˣ��»ؿ�����ô��ʰ�㣡\n\n" NOR, CYN),
        append_color(CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n\n" NOR, CYN),
        append_color(CYN "\n$n��ɫһ����˵�����������ˣ��͵���������ɣ�\n\n" NOR, CYN),
        append_color(CYN "\n$n������Ц���е������������ã��������ã���һ���������������\n\n" NOR, CYN),
        append_color(CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR, CYN),
        append_color(CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR, CYN),
        append_color(CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR, CYN),
});

void create()
{
        seteuid(getuid());
        set("channel_id", "ս������");
}

// message after damage info
static string foo_before_hit = 0;
static string foo_after_hit = 0;

void set_bhinfo(string msg)
{
        if (! foo_before_hit)
        {
                foo_before_hit = msg;
                return;
        }

        foo_before_hit += msg;
}

void set_ahinfo(string msg)
{
        if (! foo_after_hit)
        {
                foo_after_hit = msg;
                return;
        }

        foo_after_hit += msg;
}

string query_bhinfo() { return foo_before_hit; }

string query_ahinfo() { return foo_after_hit; }

void clear_bhinfo() { foo_before_hit = 0; }

void clear_ahinfo() { foo_after_hit = 0; }

string damage_msg(int damage, string type)
{
        string str;

        if (damage == 0)
                return "���û������κ��˺���\n";

        switch (type)
        {
        case "����":
        case "����":
                if (damage < 15)  return "���ֻ������ػ���$p��Ƥ�⡣\n"; else
                if (damage < 40)  return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n"; else
                if (damage < 100) return "������͡���һ����$w����$p$l����һ���˿ڣ�\n"; else
                if (damage < 200) return "������͡���һ����$w����$p$l����һ��Ѫ���ܵ��˿ڣ�\n"; else
                if (damage < 400) return "������͡���һ����$w����$p$l����һ���ֳ�������˿ڣ�����$N������Ѫ��\n"; else
                                  return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ�\n";
                break;
        case "����":
                if (damage < 15)  return "���ֻ������ش���$p��Ƥ�⡣\n"; else
                if (damage < 40)  return "�����$p$l�̳�һ�����ڡ�\n"; else
                if (damage < 100) return "������ۡ���һ����$w�Ѵ�����$n$l����\n"; else
                if (damage < 200) return "������ۡ���һ����$w�Ѵ̽�$n��$l��ʹ$p�������������˼�����\n"; else
                if (damage < 400) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ�������Ѫ������\n"; else
                                  return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ�\n";
                break;
        case "����":
        case "����":
                if (damage < 15)  return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n"; else
                if (damage < 40)  return "�����$p��$l���һ�����ࡣ\n"; else
                if (damage < 100) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n"; else
                if (damage < 150) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n"; else
                if (damage < 200) return "������项��һ����$n����������\n"; else
                if (damage < 400) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n"; else
                if (damage < 800) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"; else
                                  return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ��\n";
                break;
        case "����":
                if (damage < 15)  return "���ֻ�ǰ�$n������˰벽����������\n"; else
                if (damage < 40)  return "���$nʹ��һ������$p��$l���һ�����ˡ�\n"; else
                if (damage < 100) return "���һ�����У���$n���ʹ��������ȥ��\n"; else
                if (damage < 150) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n"; else
                if (damage < 200) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n"; else
                if (damage < 400) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"; else
                if (damage < 800) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"; else
                                  return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ��\n";
                break;
        case "��Ѩ":
                if (damage < 15)  return "���ֻ�����������$n��$l������û�е㵽Ѩ����\n"; else
                if (damage < 40)  return "���$nʹ��һ������$p��$l���һ�����ࡣ\n"; else
                if (damage < 100) return "���һ�����У�$N������$n$l�ϵ�Ѩ����$nֻ��һ����ľ��\n"; else
                if (damage < 200) return "���$n�ƺ���һ��������һ����һ��ף���ʱ����$l��ľ��\n"; else
                if (damage < 400) return "���$n��ɫһ�±�òҰף���$N����$l��Ѩ��,һ����ʹ�鲼����$l��\n"; else
                if (damage < 800) return "���$nһ����У�$l��Ѩ��������,��ʹֱ���ķΣ�\n"; else
                                  return "���ֻ����$nһ���ҽУ�һ���ʹ�����������α�ȫ������ֱͦͦ�ĵ�����ȥ��\n";
                break;
        case "����":
                if (damage < 15)  return "���ֻ����$n��Ƥ����������������ֻ���Ƶ�Ƥ��\n"; else
                if (damage < 40)  return "�����$n$l���һ����΢���Ϻۡ�\n"; else
                if (damage < 100) return "�����ž����һ����$n$l���һ��������Ѫ�ۣ�\n"; else
                if (damage < 200) return "���ֻ����ž����һ����$n��$l�����Ƥ��������ʹ��$pҧ���гݣ�\n"; else
                if (damage < 400) return "���ֻ����ž����һ����$n��$l�����Ƥ��������ʹ��$pҧ���гݣ�\n"; else
                if (damage < 800) return "�����ž����һ�����죡��һ�º�������ֻ���$nƤ��������Ѫ���ɽ���\n"; else
                                  return "���ֻ����$nһ���Һ���$w���صس�����$p��$l��$n��ʱѪ���ɣ�ʮ�����˾�����\n";
                break;
        case "������":
                if (damage < 15)  return "���$N�ܵ�$n�����������ƺ�һ����\n"; else
                if (damage < 40)  return "���$N��$n�ķ������Ѫ���ڣ���ʧɫ��\n"; else
                if (damage < 100) return "���$N��$n�ķ����վ�����ȣ�ҡҡ�λΡ�\n"; else
                if (damage < 200) return "���$N��$n���������𣬡��١���һ������������\n"; else
                if (damage < 300) return "���$N��$n����÷���������������ð����顣\n"; else
                if (damage < 400) return "���$N��$n�����������ؿ������ܵ�һ���ػ�����������������\n"; else
                if (damage < 600) return "���$N��$n����������ǰһ�ڣ���������ɳ�����\n"; else
                                  return "���$N��$n����������ǰһ�ڣ�������Ѫ������������ߵķ��������ȥ��\n";
                break;
        case "����":
                if (damage < 10)  return "���ֻ����������������Ǹ�$nɦ��һ������\n"; else
                if (damage < 40)  return "�����$n��$l�ҳ�һ��С������\n"; else
                if (damage < 100) return "���$N��һ���Ҹ����ţ�$n��$l��ʱ����һ���ϸߣ�\n"; else
                if (damage < 150) return "���$N��һ���Ҹ����ţ�$n�ƺ�һ����Ȼ���˲�С�Ŀ���\n"; else
                if (damage < 200) return "���ֻ�����项��һ����$n�۵�����������������\n"; else
                if (damage < 400) return "�����һ�¡��䡹��һ���ҵ�$n��ð���ǣ���һ��ˤ����\n"; else
                if (damage < 800) return "������ص����У�$n��ǰһ�ڣ����ۡ���һ���³�һ����Ѫ��\n"; else
                                  return "���ֻ�������䡹��һ�����죬$n���ҵ�Ѫ��ģ�����Ҳ��̶ã�\n";
        case "ǹ��":
                if (damage < 10)  return HIC "����ӵ�ֻ������ز�������û����������$n" HIC "��\n" NOR; else
                if (damage < 100) return HIR "���$N" HIR "��һǹ����$n" HIR "��$l��ֱ��$n" HIR "���Ѫ��ģ����\n" NOR; else
                                  return HIR "���$N" HIR "��һǹ����$n" HIR "��$l�������һ����ڴ��Ѫ����\n" NOR;
        default:
                if (! type) type = "�˺�";
                if (damage < 15)  str = "���ֻ����ǿ���һ����΢"; else
                if (damage < 40)  str = "��������΢��"; else
                if (damage < 100) str = "������һ��"; else
                if (damage < 150) str = "���һ������"; else
                if (damage < 200) str = "��������Ϊ���ص�"; else
                if (damage < 300) str = "�������൱���ص�"; else
                if (damage < 400) str = "������ʮ�����ص�"; else
                if (damage < 600) str = "�����ɼ������ص�"; else
                                  str = "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string eff_status_msg(int ratio)
{
        if (ratio==100) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
        if (ratio > 95) return HIG "�ƺ����˵����ˣ��������������������" NOR;
        if (ratio > 90) return HIY "�������������˵����ˡ�" NOR;
        if (ratio > 80) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
        if (ratio > 60) return HIY "���˲��ᣬ������״������̫�á�" NOR;
        if (ratio > 40) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
        if (ratio > 30) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
        if (ratio > 20) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
        if (ratio > 10) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if (ratio > 5 ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
        if (ratio==100) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if (ratio > 95) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if (ratio > 90) return HIY "������������Щ���ˡ�" NOR;
        if (ratio > 80) return HIY "�����ƺ��е㲻̫��⣬����Ȼ�������ɡ�" NOR;
        if (ratio > 60) return HIY "�������꣬������״������̫�á�" NOR;
        if (ratio > 40) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if (ratio > 30) return HIR "�м���Ȼɢ�ң�������֧����������ȥ��" NOR;
        if (ratio > 20) return HIR "�������Ѿ����������ˡ�" NOR;
        if (ratio > 10) return RED "����бб��վ��վ�����ȣ��ۿ���Ҫ���ء�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

// Doing
// Reduce the power of the combat_exp
int valid_power(int combat_exp)
{
        if (combat_exp < 2000000)
                return combat_exp;

        combat_exp -= 2000000;
        if (combat_exp < 1000000)
                return 2000000 + combat_exp / 10;

        combat_exp -= 1000000;
        return 2000000 + (1000000 / 10) + (combat_exp / 20);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage, int delta)
{
        int status, level, power;
        mapping dbase;
        mapping temp;
        mapping fight;
        mapping apply;

        if (! living(ob)) return 0;

        level = ob->query_skill(skill);

        dbase = ob->query_entire_dbase();
        temp = ob->query_entire_temp_dbase();
        if (temp)
        {
                apply = temp["apply"];
                fight = temp["fight"];
        }

        switch (usage)
        {
                case SKILL_USAGE_ATTACK:
                        if (apply) level += apply["attack"];
                        break;
                case SKILL_USAGE_DEFENSE:
                        if (apply) level += apply["defense"];
                        break;
        }

	level += delta;
        if (level < 1)
	{
		power = valid_power((int)ob->query("combat_exp")) / 2;
		if (usage == SKILL_USAGE_ATTACK)
			power = power / 30 * dbase["str"];
		else
			power = power / 30 * dbase["dex"];

	 	return  power;
	}

        if (level > 500)
                power = (level / 10) * level * level;
        else
                power = level * level * level / 10;

	power += valid_power(dbase["combat_exp"]);

        if (usage == SKILL_USAGE_ATTACK)
        {
                power = power / 30 * (dbase["str"] + (temp ? temp["str"] : 0));
                if (fight && ob->is_fighting())
                         power += power / 100 * fight["attack"];
        } else
        {
                power = power / 30 * (dbase["dex"] + (temp ? temp["dex"] : 0));
                if (fight && ob->is_fighting())
                         power += power / 100 * fight[skill];
        }
        return power;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
        mapping my, your;
        mapping my_temp, your_temp;
        mapping prepare, action;
        string limb, *limbs;
        string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
        string parry_msg;
        mixed foo;

	int delta;
        int ap, dp, pp;
        int damage, damage_bonus, defense_factor;
        int wounded;

	object weapon2;	// weapon of victim
        object cloth;   // armor of victim

	string result;
	string damage_info;
	mapping fight;

	object env_me;
	object env_v;

        if (environment(me)->query("no_fight"))
        {
                message_vision(HIW "$N" HIW "��$n" HIW "��������һ������ס���С�\n" NOR,
                               me, victim);
                me->remove_enemy(victim);
                victim->remove_enemy(me);
                return 0;
        }

        if (environment(me) != environment(victim))
        {
                me->remove_enemy(victim);
                victim->remove_enemy(me);
                return 0;
        }

        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        if (! (my_temp = me->query_entire_temp_dbase()))
                my_temp = allocate_mapping(5);

        if (! (your_temp = victim->query_entire_temp_dbase()))
                your_temp = allocate_mapping(5);

        //
        // (0) Choose skills.
        //
        prepare = me->query_skill_prepare();
        if (! prepare) prepare = ([]);

        if (objectp(weapon))
                attack_skill = weapon->query("skill_type");
        else
        {
                switch (sizeof(prepare))
                {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
                }
        }

        if (attack_skill == "pin")
                // the pin skill will the same as the sword skill,
                // why don't I remove pin skill ? because I don't
                // want the pin will be treat as sword, only at the
                // combatd, they as same.
                attack_skill = "sword";

        //
        // (1) Find out what action the offenser will take.
        //
	me->reset_action();
        action = me->query_action();

        if (! action)
	{
		// reconfirm
                me->reset_action();
                action = me->query_action();
                if (! mapp(action))
		{
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->query("name"), me->query("id"),
                                        me->query_action(1)));
                        return 0;
                }
        }

        if (me->query_temp("action_flag") == 0)
                result = "\n" + action["action"] + "��\n" NOR;
        else
                result = "\n" NOR + HIW "������" NOR + action["action"] + "��\n" NOR; 

        //
        // (2) Prepare AP, DP for checking if hit.
        //
        limbs = victim->query("limbs");
	if (! arrayp(limbs))
	{
		limbs = ({ "����" });
		victim->set("limbs", limbs);
	}
        limb = limbs[random(sizeof(limbs))];

	if (! my["not_living"])
	{
		fight = allocate_mapping(5);
		fight["attack"] = action["attack"];
		fight["dodge"]  = action["dodge"];
        	fight["parry"]  = action["parry"];
		my_temp["fight"] = fight;
	}

        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK, 0);
        if (ap < 1) ap = 1;

        if (my["character"] == "���ռ�թ")
                ap += ap * 20 / 100;

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE, 0);
        if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
        {
                dp += dp / 100 * SKILL_D(dodge_skill)->query_effect_dodge(me, victim);
        }
        if (dp < 1) dp = 1;

        if (victim->is_busy()) dp /= 3;

        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //
        damage = 0;
	wounded = 0;
	damage_info = "";
        if (random(ap + dp) < dp)
	{  // Does the victim dodge this hit?
#if INSTALL_COMBAT_TEST
                if (wizardp(me) && me->query("env/combat_test"))
                        tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                                    "��DP��" + dp + "��\n" NOR);
                if (wizardp(victim) && victim->query("env/combat_test"))
                        tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                                    "��DP��" + dp + "��\n" NOR);
#endif
                if (! dodge_skill) dodge_skill = "dodge";
                result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

                if (dp < ap && (! userp(victim) || ! userp(me)))
		{
			if (random(your["combat_exp"]) < EXP_LIMIT && random(2))
                        {
                        	your["combat_exp"]++;
                                victim->improve_skill("dodge", 1);
                        }
                }
        } else
	{
                //
                //      (4) Check if the victim can parry this attack.
                //
                if (! userp(me) || ! userp(victim))
                {
                        if (ap < dp && random(my["int"]) > 8)
                        {
                                if (my["potential"] < me->query_potential_limit())
                                        my["potential"]++;
                                me->improve_skill(attack_skill, 1);
                        }
                }
		delta = 0;
		if (weapon2 = your_temp["weapon"])
		{
			if (! weapon) delta = 10;
		} else
		{
			if (weapon) delta = -10;
		}
                pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE, delta);

                if (victim->is_busy()) pp /= 3;
                if (pp < 1) pp = 1;

                if (stringp(parry_skill = victim->query_skill_mapped("parry")))
                        pp += pp / 100 * SKILL_D(parry_skill)->query_effect_parry(me, victim);

                if (random(ap + pp) < pp)
                {
#if INSTALL_COMBAT_TEST
                        if (wizardp(me) && me->query("env/combat_test"))
                                tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                                            "��PP��" + pp + "��\n" NOR);
                        if (wizardp(victim) && victim->query("env/combat_test"))
                                tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                                            "��PP��" + pp + "��\n" NOR);
#endif
                        if (! parry_skill) parry_skill = "parry";
                        // change to SKILL_D(parry_skill) after added parry msg to those
                        // martial arts that can parry.
                        parry_msg = SKILL_D(parry_skill)->query_parry_msg(weapon2);

                        if (! stringp(parry_msg))
                                parry_msg = SKILL_D("parry")->query_parry_msg(weapon2);

                        if (stringp(parry_msg))
                                result += parry_msg;

                        if (pp < ap && (! userp(victim) || ! userp(me)))
                        {
				if (random(your["combat_exp"]) < EXP_LIMIT && random(2))
                                {
                                	your["combat_exp"]++;
                                        victim->improve_skill("parry", 1);
                                }
                        }
                } else
                {
                        //
                        //      (5) We hit the victim and the victim failed to parry
                        //

                        if (weapon)
                                damage = me->query_temp("apply/damage");
                        else
                                damage = me->query_temp("apply/unarmed_damage");
                        damage = (damage + random(damage)) / 2;
                        if (action["damage"])
                                damage += action["damage"] * damage / 100;

                        damage_bonus = me->query_str();
                        if (my["jianu"])
                        {
                                // does angry bnous
                                damage_bonus += me->cost_craze(my["jianu"]);
                                if (me->query_craze() > 1000 &&
                                    random(my["jianu"] + 200) > 200)
                                {
                                        damage_info += random(2) ? HIR "$N" HIR "���һ����˫ĿԲ����һ��������ɱ����Ȼ����\n" NOR
                                                                 : HIR "$N" HIR "�ܲ����������ǰ�������н���$n" HIR "���������顣\n" NOR;
                                        me->cost_craze(200 + random(300));
                                        damage_bonus += my["jianu"] * 2;
                                }
                        }

                        // Clear the special message info after damage info
                        foo_before_hit = 0;
                        foo_after_hit = 0;

                        // Let force skill take effect.
                        if (my["jiali"] && (my["neili"] > my["jiali"]))
			{
                                if (force_skill = me->query_skill_mapped("force"))
				{
                                        foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage_bonus += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage_bonus += foo["damage"];
                                        }
                                }
#if INSTALL_COMBAT_TEST
                                if (wizardp(me) && me->query("env/combat_test"))
                                        tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                                                    "��DP��" + dp + "��PP��" + pp +
                                                    "�����⹥��Ч����" + damage_bonus +
                                                    "�������Ա�Ч����" + foo + "��\n" NOR);
                                if (wizardp(victim) && victim->query("env/combat_test"))
                                        tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                                                    "��DP��" + dp + "��PP��" + pp +
                                                    "�����⹥��Ч����" + damage_bonus +
                                                    "�������Ա�Ч����" + foo + "��\n" NOR);
#endif
                        }

                        if (action["force"])
                                damage_bonus += action["force"] * damage_bonus / 100;

                        // calculate the damage
                        if (damage_bonus > 0)
                                damage += (damage_bonus + random(damage_bonus)) / 3;

                        // Let's attack & parry skill, weapon & armor do effect
                        while (damage > 0)
                        {
                                if (my["not_living"] || your["not_living"])
                                        // Only two living do this
                                        break;

                                if (damage < 1) break;

                                // Let parry skill take its special effort.
                                if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
                                {
                                        foo = SKILL_D(dodge_skill)->valid_damage(me, victim, damage, weapon);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                        if (damage < 1) break;
                                }

                                if (stringp(parry_skill = victim->query_skill_mapped("parry")))
                                {
                                        foo = SKILL_D(parry_skill)->valid_damage(me, victim, damage, weapon);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                        if (damage < 1) break;
                                }

                                // Let armor/cloth take its special effort
                                if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["armor"]))
                                {
                                        foo = cloth->valid_damage(me, victim, damage, weapon);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                } else
                                if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["cloth"]))
                                {
                                        foo = cloth->valid_damage(me, victim, damage, weapon);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                }
        
                                if (damage < 1) break;

                                // Let attack skill take its special effort.
                                if (martial_skill = me->query_skill_mapped(attack_skill))
                                {
                                        foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                        if (damage < 1) break;
                                }

                                // Let weapon or living have their special damage.
                                if (weapon)
                                {
                                        foo = weapon->hit_ob(me, victim, damage);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                } else
                                {
                                        foo = me->hit_ob(me, victim, damage);
                                        if (stringp(foo)) damage_info += foo; else
                                        if (intp(foo)) damage += foo; else
                                        if (mapp(foo))
                                        {
                                                damage_info += foo["msg"];
                                                damage += foo["damage"];
                                        }
                                }

                                // finish
                                break;
                        }

                        //
                        //      (6) Inflict the damage.
                        //

#if INSTALL_COMBAT_TEST
                        if (wizardp(me) && me->query("env/combat_test"))
                                tell_object(me, HIY "�����Ծ��顿�����" +
                                            victim->query("name") + "���" +
                                            damage + "���˺���\n" NOR);
                        if (wizardp(victim) && victim->query("env/combat_test"))
                                tell_object(victim, HIG "�����Ծ��顿�����ܵ�" +
                                            me->query("name") + damage + "���˺���\n" NOR);
#endif

                        if (damage > 0)
                        {
                                if (my["character"] == "�ĺ�����")
                                        damage += damage * 20 / 100;

                                // calculate wounded
                                wounded = damage;
                                if (mapp(your_temp["apply"]) && your_temp["apply"]["armor"] > 0)
                                        wounded -= random(your_temp["apply"]["armor"]);

                                if (wounded > 400)
                                        wounded = (wounded - 400) / 4 + 300;
                                else
                                if (wounded > 200)
                                        wounded = (wounded - 200) / 2 + 200;
                                else
                                if (wounded < 1)
                                        wounded = 0;

                                // recalculate damage
                                if (damage > 400)
                                        damage = (damage - 400) / 4 + 300;
                                else
                                if (damage > 200)
                                        damage = (damage - 200) / 2 + 200;

                                if (your["character"] == "��������")
                                        wounded -= wounded * 20 / 100;

                                damage = victim->receive_damage("qi", damage, me);
                                if (wounded > 0 &&
                                    ((me->is_killing(your["id"]) && random(3) == 1) ||
                                     random(3) == 1))
                                {
                                        // We are sure that damage is greater than victim's armor here.
                                        victim->receive_wound("qi", wounded, me);
                                }

                                // add message before hit in victim
                                if (foo_before_hit)
                                        result += foo_before_hit;

                                result += damage_msg(damage, action["damage_type"]);
                                damage_info += "( $n" + status_msg(victim->query("qi") * 100 / victim->query("max_qi")) + ")\n";
                        }

                        if (foo_after_hit)
                                damage_info += foo_after_hit;
                }
        } 

        result = replace_string(result, "$l", limb);
        if (objectp(weapon))
                result = replace_string(result, "$w", weapon->name());
        else if (objectp(weapon = me->query_temp("weapon")))
                result = replace_string(result, "$w", weapon->name());
        else if (stringp(action["weapon"]))
                result = replace_string(result, "$w", action["weapon"]);
        else if (attack_skill == "finger" || attack_skill == "hand")
                result = replace_string(result, "$w", "��ָ" );
        else if (attack_skill == "strike" || attack_skill == "claw")
                result = replace_string(result, "$w", "����" );
        else    result = replace_string(result, "$w", "ȭͷ" );

        message_combatd(result, me, victim, damage_info);

        if (damage > 0)
	{
                if (victim->is_busy()) victim->interrupt_me(me, 8 + random(4));
                if ((! me->is_killing(your["id"])) && 
                    (! victim->is_killing(my["id"])) &&
                    ! victim->query("not_living") &&
                    your["qi"] * 3 <= your["max_qi"])
		{
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
                        message_vision(winner_msg[random(sizeof(winner_msg))],
				       me, victim);
                        if (me == victim->query_competitor())
                        {
                                me->win();
                                victim->lost();
                        }
                }
        }

        if (functionp(action["post_action"]))
                evaluate(action["post_action"], me, victim, weapon, damage);

        // See if the victim can make a riposte.
        if (attack_type == TYPE_REGULAR &&
            damage < 1 &&
            your_temp["guarding"])
	{
                your_temp["guarding"];
                if (random(my["dex"]) < 5)
                {
                        message_combatd(HIC "$N" HIC "һ�����У�¶����������\n" NOR,
					me, 0, "");
                        do_attack(victim, me, your["weapon"],
				  TYPE_QUICK);
                } else
                {
                        message_combatd(HIC "$N" HIC "��$n" HIC "����ʧ�󣬳û�����������\n" NOR,
				        victim, me, "");
                        do_attack(victim, me, your["weapon"],
				  TYPE_RIPOSTE);
                }
        }
}

// do damage when perform
// I will consider the damage of the weapon
// what is final: final may be a function with result type string,
// or a single string.
// The syntax of the final string is info:damage_type@limb or info only,
// If the limb if ?, the system will auto select limb of
// target, if the final is a single string, the system will
// treat as damage infomation.
varargs string do_damage(object me, object target, mixed type,
                         int damage, int percent, mixed final)
{
        mapping my;
        object weapon;
        object cloth;
        int apply;
        int armor;
        int wound;
        int jiali;
        int bonus;
        mixed foo;
        string msg;
        string skill;
        string *limbs;
        string limb;
        string damage_type;
        string result;
        int str;
        int damage_bonus;

        // Am I use weapon
        if (type == WEAPON_ATTACK)
        {
                apply  = me->query_temp("apply/damage");
                weapon = me->query_temp("weapon");
        } else
        if (type == UNARMED_ATTACK)
        {
                apply  = me->query_temp("apply/unarmed_damage");
                weapon = 0;
        } else
        {
                apply  = 0;
                weapon = 0;
        }

        // Check the target's armor
        armor = target->query_temp("apply/armor");

        damage += apply;
        msg = "";
        foo_after_hit = 0;

        while (type == UNARMED_ATTACK || type == WEAPON_ATTACK)
        {
                // Let parry skill take its special effort
                if (skill = target->query_skill_mapped("parry"))
                {
                        foo = SKILL_D(skill)->valid_damage(me, target, damage, weapon);
                        if (stringp(foo)) msg += foo; else
                        if (intp(foo)) damage += foo; else
                        if (mapp(foo))
                        {
                                msg += foo["msg"];
                                damage += foo["damage"];
                        }
                }

                if (damage < 1) break;
                // Let cloth & armor take its special effort
                if (cloth = target->query_temp("armor/armor"))
                {
                        foo = cloth->valid_damage(me, target, damage, weapon);
                        if (stringp(foo)) msg += foo; else
                        if (intp(foo)) damage += foo; else
                        if (mapp(foo))
                        {
                                msg += foo["msg"];
                                damage += foo["damage"];
                        }
                } else
                if (cloth = target->query_temp("armor/cloth"))
                {
                        foo = cloth->valid_damage(me, target, damage, weapon);
                        if (stringp(foo)) msg += foo; else
                        if (intp(foo)) damage += foo; else
                        if (mapp(foo))
                        {
                                msg += foo["msg"];
                                damage += foo["damage"];
                        }
                }

                // Finish
                break;
        }

        while (damage > 0)
        {
                if (target->is_busy()) target->interrupt_me(target, 4 + random(4));

                // Let weapon/unarmed attack take its special effort
                if (type == WEAPON_ATTACK)
                        // weapon attack
                        foo = weapon->hit_ob(me, target, damage);
                else
                if (type == UNARMED_ATTACK)
                        // unarmed attack
                        foo = me->hit_ob(me, target, damage);
                else
                if (objectp(type))
                        // special item attack
                        foo = type->hit_ob(me, target, damage);

                if (stringp(foo)) msg += foo; else
                if (intp(foo)) damage += foo; else
                if (mapp(foo))
                {
                        msg += foo["msg"];
                        damage += foo["damage"];
                }

                // do enforce effect
                my = me->query_entire_dbase();
                if ((jiali = my["jiali"]) > 0 && my["neili"] >= jiali)
                {
                        // eforced
                        my["neili"] -= jiali;
                        if (type == REMOTE_ATTACK)
                        {
                                damage_bonus = jiali * damage / 200;
                        } else
                        {
                                damage_bonus = jiali * damage / 300;
        
                                // check special force effort
                                skill = target->query_skill_mapped("force");
                                if (stringp(skill))
                                {
                                        foo = SKILL_D(skill)->valid_damage(me, target, damage_bonus);
                                        if (stringp(foo)) msg += foo; else
                                        if (intp(foo)) damage_bonus += foo; else
                                        if (mapp(foo))
                                        {
                                                msg += foo["msg"];
                                                damage_bonus += foo["damage"];
                                        }
                                }
                                damage += damage_bonus;
                        }
                }

                // do strength effect
                str = me->query_str() + me->query_temp("str");
                if (str < 20)
                        damage += damage * str / 50;
                else
                if (str < 40)
                        damage += damage * ((str - 20) / 2 + 20) / 50;
                else
                        damage += damage * ((str - 40) / 4 + 30) / 50;

                if (damage < 1) break;

                // recalculate damage
                if (damage > 1500)
                        damage = (damage - 1500) / 4 + 1000;
                else
                if (damage > 500)
                        damage = (damage - 500) / 2 + 500;

                // do damage
                target->receive_damage("qi", damage, me);
                wound = (damage - random(armor)) * percent / 100;
                if (target->query("character") == "��������")
                        wound -= wound * 20 / 100;
                if (wound > 0) target->receive_wound("qi", wound, me);
                if (functionp(final)) final = evaluate(final);
                if (stringp(final))
                {
                        if (sscanf(final, "%s@%s", final, limb) == 2)
                        {
                                if (sscanf(final, "%s:%s", result, damage_type) != 2)
                                {
                                        result = HIR "���д��˸����У�";
                                        damage_type = final;
                                }
                                if (sscanf(limb, "?%*s"))
                                {
                                        // auto select limb
                                        limbs = target->query("limbs");
                                	if (! arrayp(limbs))
                                	{
                                		limbs = ({ "����" });
                                		target->set("limbs", limbs);
                                	}
                                        limb = limbs[random(sizeof(limbs))];
                                }

                                // indicate damage type & limb
                                final = replace_string(damage_msg(damage, damage_type), "$l", limb);
                                final = replace_string(final, "$n", "$n" HIR);
                                final = replace_string(final, "$N", "$N" HIR);
                                final = replace_string(final, "$p", "$p" HIR);
                                final = replace_string(final, "$P", "$P" HIR);
                                if (weapon)
                                        final = replace_string(final, "$w", weapon->name() + HIR);
                                final = result + HIR + final + NOR;
                        }

                        msg += final;
                        msg += "( $n" + status_msg(target->query("qi") * 100 / target->query("max_qi")) + ")\n";
                }

                break;
        }

        if (foo_after_hit) msg += foo_after_hit;
        return msg;
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        object ob;
        object weapon;
        string askill;
        int    double_attack;
        mapping prepare;
        string result;

        if (! living(me)) return;

        prepare = me->query_skill_prepare();
        if (weapon = me->query_temp("weapon")) askill = weapon->query("skill_type");
        else if (! prepare || sizeof(prepare) == 0) askill = "unarmed";
        else if (sizeof(prepare)) askill = (keys(prepare))[0];
        if (askill == "pin") askill = "sword";

        askill = me->query_skill_mapped(askill);
        if (askill && random(me->query_dex()) >= 8)
                double_attack = (sizeof(prepare) >= 2 && ! weapon) ||
				SKILL_D(askill)->double_attack();

        // If victim is busy or unconcious, always take the chance to make an attack.
        if (victim->is_busy() || ! living(victim))
        {
                me->set_temp("guarding", 0);
                if (! victim->is_fighting(me)) victim->fight_ob(me);
                do_attack(me, victim, weapon, TYPE_QUICK);

                if (me->is_fighting(victim) && victim->is_fighting(me) && double_attack)
                {
                        me->set_temp("action_flag",1);
                        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                        me->set_temp("action_flag",0);
                }

        // Else, see if we are brave enough to make an aggressive action.
	} else
        if (me->query_str() > random(victim->query_str() * 3 / 4))
        {
                me->set_temp("guarding", 0);
                if (! victim->is_fighting(me))
                        victim->fight_ob(me);
                do_attack(me, victim, weapon, TYPE_REGULAR);

                if (me->is_fighting(victim) && victim->is_fighting(me) && double_attack)
                {
                        me->set_temp("action_flag",1);
                        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
                        me->set_temp("action_flag",0);
                }

        // Else, we just start guarding.
        } else
        if (! me->query_temp("guarding"))
        {
                me->set_temp("guarding", 1);
                message_combatd( guard_msg[random(sizeof(guard_msg))], me, victim, "");
                return;
        } else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if (! userp(me) && ! userp(obj)) return;

        if (me->query_temp("owner") == obj ||
            obj->quety_temp("owner") == me)
                return;

        // Because most of the cases that we cannot start a fight cannot be checked
        // before we really call the kill_ob(), so we just make sure we have no 
        // aggressive callout wating here.
        if (me->query_temp("looking_for_trouble")) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out("start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
        int shen;

        // Are we still exist( not becoming a corpse )?
        if (! me || ! obj || ! living(me)) return;

        me->set_temp("looking_for_trouble", 0);

        if (me->is_fighting(obj) ||
            environment(me)!=environment(obj) ||
            environment(me)->query("no_fight"))
        	return;

        shen = 0 - (int)me->query("shen");
        message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

        if (! userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 )
		return;

        if (shen > (int)me->query("score") && ! wizardp(obj))
	{
                message_vision(HIW "$N" HIW "����$n" HIW "�ȵ���" +
                               RANK_D->query_self_rude(me) + "����ʵ"
                               "�ںܲ�˳�ۣ�ȥ���ɡ�\n" NOR, me, obj);
                me->kill_ob(obj);
        } else
	{
                message_vision(HIW "$N" HIW "����$n" HIW "�ȵ���ι��" +
                               RANK_D->query_rude(obj) + HIW "��" +
                               RANK_D->query_self_rude(me) + HIW "����"
                               "���˴�ܣ����������ְɣ�\n" NOR, me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
        if (! me || ! obj || ! living(me))
		return;

        me->set_temp("looking_for_trouble", 0);

        if (me->is_fighting(obj) ||
            environment(me) != environment(obj) ||
            environment(me)->query("no_fight"))
		return;

        if (me->query_temp("owner") == obj->query("id") ||
            obj->query_temp("owner") == me->query("id"))
                return;

        // We found our hatred! Charge!
        message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->want_kill(obj);
        me->kill_ob(obj);

        if (! playerp(me) && me->is_busy() && ! intp(me->query_busy()))
                me->interrupt_me(me);
}

void start_vendetta(object me, object obj)
{
        if (! me || ! obj || ! living(me))
		return;

        me->set_temp("looking_for_trouble", 0);

        if (me->is_fighting(obj) ||
            environment(me) != environment(obj) ||
            environment(me)->query("no_fight"))
		return;

        // We found our vendetta opponent! Charge!
	me->want_kill(obj);
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if (! me || ! obj || ! living(me)) return;

        me->set_temp("looking_for_trouble", 0);

        if (me->is_fighting(obj) ||
            environment(me) != environment(obj) ||
            environment(me)->query("no_fight"))
                return;

        // We got a nice victim! Kill him/her/it!!!
        me->want_kill(obj);
        me->kill_ob(obj);
}

int player_escape(object killer, object ob)
{
        object iob;
        string msg;

        if (! objectp(ob))
                return 0;

        // �����ô��
        if (! playerp(ob))
                return 0;

        if ((int)ob->query("combat/which_day") == time() / 86400 &&
            (int)ob->query("total_count") > 0)
                return 0;

        // ����ε��ˣ��쿴�Ƿ��Ǳ�����������ε�
        if (! killer) killer = ob->query_defeated_by();
        if (! killer || ! playerp(killer) ||
            ! killer->is_want_kill(ob->query("id")))
                return 0;

        if (ob->query("combat_exp") >= 100000)
                return 0;

        switch (random(5))
        {
        case 0:
                msg = HIW "\n$NͻȻ�������һ����ߣ�ֻ��һ�����ᰴ����$N��"
                      "��һ�����������˼����ֻ��̧��һ�񡣴�æ֮��ֻ�¶���"
                      "���������������мܣ���æ���Ծ����ȴ�����˲�������׷"
                      "����ֻ��һ��������$n��ת�������󲽣�˲�伴�š�\n\n"
                      NOR;
                break;

        case 1:
                msg = HIW "\n$N��$n���ڵأ���������һ��Ц����δ���£�ֻ��"
                      "����������һ������Ȼ���Ʒ�Ϯ�壬$N�ٸк�����������"
                      "����Ϣ����æ�м�æ�˺󣬴������ȽŸ���ȴ��$n������Ӱ"
                      "���١�\n\n" NOR;
                break;

        case 2:
                msg = HIW "��Ȼ��һ���������ȵ��������д����ҹ�ĳ��ޱ���"
                      "�����¶�֮ͽ��ס�֣���˵��һ�ƻ�����$N�����мܣ�һ��"
                      "֮�¼�����Ѫ��ֻ��������������$n�����һ����ת����ȥ"
                      "��$N����֮�£���Ȼ˵����һ�仰����\n\n" NOR;
                break;

        case 3:
                msg = HIW "ͻȻ����һ�˺ȵ�������������ֻ��һ����Ӱ�ӵ�����"
                      "��һչ�ѵ���$N��ǰ����������$n����Ϊ�߿��ض�$N������"
                      "����������δ��������������δ��̫�����У���$N��ֵ����"
                      "�䣬ȴ�������˾�������$n�������󲽣�ת˲���š�\n\n"
                      NOR;
                break;

        default:
                msg = HIW "$N��Ȼ���á��ס���һ������æת��ͷ�����������"
                      "֪��ʱ����һ������򸾣��Լ�ȫȻδ�ܾ��졣ֻ����Ů��"
                      "˵����������磬�㿴���˺����Ե�������Ҫ�Ͼ�ɱ������"
                      "�����ӳ������������ǣ�����ͽ��˾��𡣡�˵������Ծ"
                      "��$N��ǰ��$N��ʱ�󾪣������������ӹ������У���������"
                      "��Ҳ������������$n��ת��������󲽣��ͷ�����Ů��һ"
                      "����ʧ����Ӱ���١�\n\n";
                break;
        }

        if ((environment(killer) == environment(ob)) &&
            killer->is_fighting(ob))
        {
                msg = replace_string(msg, "$n", ob->name());
                message_sort(msg, killer);
        } else
        {
                msg = HIW "��ʱ����һ����·��������" + ob->name() + HIW
                      "�ε��ڵأ�����һ�����漴���������ڱ��ϣ��粽Զȥ"
                      "��\n" NOR;
                message("vision", msg, environment(ob));
        }

        // �����ϱ����˷���
        foreach (iob in deep_inventory(ob))
                if (iob->is_character())
                        iob->move_environment(ob);

        // ��ʼ����ҵ�״̬
        ob->clear_condition();
        ob->remove_killer(killer);
        killer->remove_killer(ob);

        ob->move("/d/wuguan/guofu_dating");
        ob->set("startroom", "/d/wuguan/guofu_dayuan");
        ob->revive();
        ob->set("eff_qi", ob->query("max_qi"));
        ob->set("eff_jing", ob->query("max_jing"));
        ob->set("qi", 0);
        ob->set("jing", 0);
        ob->set_temp("mark/guofu_wait", 1);
        tell_object(ob, HIW "����������������һλ��̬���������������΢Ц"
                        "��ע�����㡣\n\n" NOR + HIC "��������΢Ц����" +
                        RANK_D->query_respect(ob) + "���������ˡ��мǽ���"
                        "�ն񣬻�����\n�ף��Ժ����߽�����Ҫ���С�Ľ�����"
                        "\n" NOR);

        if (! ob->query("mark/guofu_ok")
	   && ! ob->query("mark/guofu_out")
	   && ! ob->query("mark/guofu_over")
	   && ob->query("combat_exp") < 5000)
	{
        	tell_object(ob, HIC "\n������˼Ƭ�̣�����˵���������ڳ���"
                                "̫��Σ�գ����Ƕ�����\n�Ҹ���һ��ʱ�䡣��"
                                "��ʱ�������˳��︮���������飬Ҳ��\nǿ"
                                "���壬���������Լ�������������������"
                                "���㰲�š�\n\n" NOR);
                ob->set("mark/guofu_ok", 1);
	}
        return 1;
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch (event)
        {
        case "dead":
                message_vision(NOR "\n$N���ڵ��������˼��£���һ�죬�����������"
                               HIR "��Ѫ" NOR "�����ˣ�\n\n" NOR, ob);
                break;

        case "unconcious":
                message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
                player_escape(0, ob);
                break;

        case "revive":
                message_vision(HIC "\n$N" HIC "���������۾��������˹�����\n\n" NOR, ob);
                break;
        }
}

// called when winner hit the victim to unconcious
void winner_reward(object winner, object victim)
{
        object owner;
        int temp;
        int td;
        mapping today;

        owner = winner->query_temp("owner");
        if (objectp(owner))
                winner = owner;

        winner->defeated_enemy(victim);

        if (! playerp(winner) || wizardp(victim) && 0)
                return;

        if (! winner->is_want_kill(victim->query("id")))
                // only if I want kill ob, I will record it.
                return;

        winner->add("combat/DPS", 1);
        if (victim->is_not_bad())  winner->add("combat/DPS_NOTBAD", 1);
        if (victim->is_not_good()) winner->add("combat/DPS_NOTGOOD", 1);
        if (victim->is_bad())      winner->add("combat/DPS_BAD", 1);
        if (victim->is_good())     winner->add("combat/DPS_GOOD", 1);

        if (victim->query_condition("killer"))
                return;

	if (victim->query("combat_exp") < 150)
		return;

        log_file("static/killrecord",
                 sprintf("%s %s defeat %s\n",
	                 log_time(), log_id(winner), log_id(victim)));

        td = time() / 86400;
        today = winner->query("combat/today");

        if (! mapp(today) || today["which_day"] != td)
        {
                today = ([ "which_day" : td,
			   "total_count" : 1,
			   victim->query("id") : 1, ]);
        } else
        {
                // count how many times that winner hit the victim to unconcious
                temp = ++today[victim->query("id")];

                // �������ҵ���������
                winner->clear_condition("die_guard");

                if (temp == MAX_KILL_TIMES_PERMAN)
                {
                        // reach limit
                        tell_object(winner, BLINK HIR "\n�������Ѿ�����" +
                                    victim->name() + chinese_number(temp) +
				    "���ˣ�������"
                                    "��ɣ������鷳��Ҫ�������ˡ�\n" NOR);
                } else
                if (temp > MAX_KILL_TIMES_PERMAN)
                        // too many times
                        winner->set("combat/need_punish", "���˱���̫�����������д���");

                // count how many users that winner hit to unconcious
                temp = ++today["total_count"];
                if (temp == MAX_KILL_TIMES_PERDAY)
                {
                        // reach limit
                        tell_object(winner, BLINK HIR "\n�������Ѿ�����" +
                                    chinese_number(temp) + "������ˣ�������"
                                    "��ɣ������鷳��Ҫ�������ˡ�\n" NOR);
                } else
                if (temp > MAX_KILL_TIMES_PERDAY)
                        // too many users
                        winner->set("combat/need_punish", "ɥ��������������¾�����޿�ˡ��");
        }
        winner->set("combat/today", today);
}

void killer_reward(object killer, object victim)
{
        object owner;
        string vmark;
        string msg = "Ī�����������";
        string follow_msg = 0;
        object weapon;
        mapping actions;
        int shen_delta;
        mapping ks, vs, kcombat;

        if (! objectp(victim))
                return;

        if (objectp(killer))
        {
                owner = killer->query_temp("owner");
                if (objectp(owner))
                        killer = owner;
        }

        // This while is only to enable "break"
        vs = victim->query_entire_dbase();
        while (1)
        {
                if (! objectp(killer))
                        break;

                // call the killer's override function
                killer->killed_enemy(victim);

                if (! objectp(killer) || ! playerp(killer))
                        break;

                // assure the killer's dbase
                ks = killer->query_entire_dbase();
                if (! mapp(kcombat = ks["combat"]))
                {
                        kcombat = ([ ]);
                        ks["combat"] = kcombat;
                }

                // adjust the "shen" & "experience" of the killer
                if (ks["combat_exp"] < vs["combat_exp"])
                {
                        if (ks["combat_exp"] >= 100000 &&
                            ks["combat_exp"] >= vs["combat_exp"] * 2 / 3)
                        {
                                // adjust experience
                                if (! intp(ks["experience"]))
                                        ks["experience"] = 0;
                                killer->improve_experience(1 + random(5));
                        }

                        // adjust shen
                        shen_delta = -vs["shen"] / 10;
                        if (shen_delta > 100)
                        {
                                // ������У����õ�����
                                shen_delta = (shen_delta - 100) / 3 + 100;

                                if (shen_delta > 200)
                                        shen_delta = (shen_delta - 200) / 3 + 200;

                                if (shen_delta > 300)
                                        shen_delta = (shen_delta - 300) / 3 + 300;
                        } else
                        if (shen_delta < -100)
                        {
                                // ������У����õĸ���
                                shen_delta = (shen_delta + 100) / 3 - 100;

                                if (shen_delta < -200)
                                        shen_delta = (shen_delta + 200) / 3 - 200;

                                if (shen_delta < -300)
                                        shen_delta = (shen_delta + 300) / 3 - 300;
                        }
                                        
                        ks["shen"] += shen_delta;
                }

                // weapon get the bonus
                if (weapon = killer->query_temp("weapon") ||
                    weapon = killer->query_temp("armor/hands"))
                        weapon->killer_reward(killer, victim);

                // record the user's killing
                if (userp(victim))
                {
                        if (! intp(kcombat["PKS"]))
                                kcombat["PKS"] = 1;
                        else
                                kcombat["PKS"]++;

                        // do family action
                        FAMILY_D->family_kill(killer, victim);

                        // do league action
                        LEAGUE_D->league_kill(killer, victim);

                        if (victim->query_condition("killer"))
                        {
                                follow_msg = "��˵ɱ������" + victim->name(1) +
                                             "��" + killer->name(1) + "��" +
                                             environment(victim)->short() + HIM
                                             "�͵������ˡ�";
                                break;
                        }

                        if (! killer->is_want_kill(vs["id"]))
                                break;

                        if (! intp(kcombat["WPK"]))
                                kcombat["WPK"] = 1;
                        else
                                kcombat["WPK"]++;

                        // �������ҵ���������
                        killer->clear_condition("die_guard");

                        if (! killer->query_condition("killer"))
                        {
                                follow_msg = "��˵�ٸ����º������飬����ɱ������" +
                                             killer->name(1) + "��";
                                killer->apply_condition("killer", 500);
                        } else
                        {
                                follow_msg = "��˵�ٸ��ӽ�׽���۷��ذ��ı�ͽ" +
                                             killer->name(1) + "��";
                                killer->apply_condition("killer", 800 +
                                        (int)killer->query_condition("killer"));
                        }

                        // assure data of kcombat
                        if (! intp(kcombat["WPK_NOTBAD"])) kcombat["WPK_NOTBAD"] = 0;
                        if (! intp(kcombat["WPK_NOTGOOD"])) kcombat["WPK_NOTGOOD"] = 0;
                        if (! intp(kcombat["WPK_GOOD"])) kcombat["WPK_GOOD"] = 0;
                        if (! intp(kcombat["WPK_BAD"])) kcombat["WPK_BAD"] = 0;

                        // record the combat info.
			if (victim->is_not_bad())  kcombat["WPK_NOTBAD"]++;
			if (victim->is_not_good()) kcombat["WPK_NOTGOOD"]++;
			if (victim->is_good())     kcombat["WPK_GOOD"]++;
			if (victim->is_bad())      kcombat["WPK_BAD"]++;
                        break;
                }

                if (vs["can_speak"])
                        if (! intp(kcombat["MKS"]))
                                kcombat["MKS"] = 1;
                        else
                                kcombat["MKS"]++;

                break;
        }

        // die penalty & message of victim
        if (playerp(victim))
        {
                // clear punish info.
                victim->delete("combat/need_punish");

                // clear all condition
                victim->clear_condition();

                // ������������
                victim->apply_condition("die_guard", 6000);

                if (victim->query("skybook/guard/death") < 1
                   && victim->query_temp("guard_death") < 1)
                {
                        // adjust shen
                        vs["shen"] -= vs["shen"] / 10;

                        if (vs["max_neili"] >= 20)
                                vs["max_neili"] -= 20;
                        else
                                vs["max_neili"] = 0;

                        // adjust combat exp.
                        vs["combat_exp"] -= vs["combat_exp"] * 3 / 100;

                        // adjust weiwang
                        vs["weiwang"] -= vs["weiwang"] / 10;

                        // adjust score
                        vs["score"] -= vs["score"] / 10;

                        // remove vendetta
                        map_delete(vs, "vendetta");

                        // lost half of potential
                        if (vs["potential"] > vs["learned_points"])
                                vs["potential"] += (vs["learned_points"] - vs["potential"]) / 2;

                        // lost half of experience
                        if (vs["experience"] > vs["learned_experience"])
                                vs["experience"] += (vs["learned_experience"] - vs["experience"]) / 2;

                        victim->skill_death_penalty();
                } else
                {
                        if (! victim->query_temp("guard_death"))
                                victim->add("skybook/guard/death", -1);

                        victim->add("skybook/no_death", 1);
                }

                // generate message of die reason
                if (objectp(killer) && killer->is_character())
                {
                        msg = "��" + filter_color(killer->name(1));
                        actions = killer->query_action();
                        switch (mapp(actions) ? actions["damage_type"] : "ɱ��")
                        {
                        case "����":
                        case "����":
                                msg+="������";
                                break;
                        case "����":
                                msg+="������";
                                break;
                        case "����":
                        case "����":
                                msg+="������";
                                break;
                        case "ǹ��":
                                msg+="��ǹ������";
                                break;
                        case "����":
                                msg+="������";
                                break;
                        default:
                                msg+="ɱ����";
                        }
                }
                if (stringp(victim->query_temp("die_reason")))
                        msg = filter_color(victim->query_temp("die_reason"));

                victim->delete_temp("die_reason");
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("��˵%s" HIM + msg + "��", victim->name(1)));

                // show the follow msg after victim die
                if (follow_msg)
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                              follow_msg);

		victim->set("combat/last_die", filter_color(msg));
                if (objectp(killer) && playerp(killer) && playerp(victim))
                {
                        string cname;
                        object couple;

                        log_file("static/killrecord",
                                 sprintf("%s %s killed %s\n",
					 log_time(),
					 log_id(killer), log_id(victim)));

                        killer->remove_killer(victim);

                        // check sadly
                        cname = victim->query("couple/id");
                        if (cname &&
                            victim->query("gender") == "Ů��" &&
                            victim->query("combat_exp") >= 970000 &&
                            objectp(couple = find_player(cname)) &&
                            couple != killer)
                        {
                                couple->add("static/sadly", 1);
                                tell_object(couple, "�������������" +
                                            killer->name(1) + "������" +
                                            "����е���һ������İ��ˡ�\n");
                        }
                }
        }

        if (stringp(vmark = victim->query("vendetta_mark")) && objectp(killer))
                killer->add("vendetta/" + vmark, 1);
}

// me hit victim with poison in ob
void hit_with_poison(object me, object victim, object ob)
{
        mapping p, ap;
        string msg;
	string poison_type;

        if (! mapp(p = ob->query_temp("daub/poison")))
                return;

        if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
                return;

        if (! p["remain"])
                return;

        // affect parameter
        ap = allocate_mapping(4);
        if (ob == me)
                ap["level"] = p["level"] * 9 / 10 + 1;
        else
                ap["level"] = p["level"] * 8 / 10 + 1;
                
        ap["id"]       = p["id"];
        ap["name"]     = p["name"];
        ap["duration"] = 1;

        if (p["remain"] > p["level"])
        {
                // decrase the remain poison
                p["remain"] -= p["level"];
        } else
        {
                // the poison has run out
                ob->delete_temp("daub");
        }

        msg = HIB "ͻȻ$n" HIB "�������˵ĵط���һЩ����";
        if (p["id"] == victim->query("id"))
        {
                if (! victim->query_temp("has_announce/defense1"))
                {
                        victim->set_temp("has_announce/defense1", 1);
                        victim->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", victim :), victim), 15);
                        msg += "��\n" NOR HIC "$n" HIC "Ĭһ�˹�����Ц���������ø�" +
                               RANK_D->query_rude(me) + "����Ȼ������ǰ��Ū" +
                               RANK_D->query_self_rude(victim) +
                               "��ҩ����\n" NOR;
                } else
                        msg += "������$n��û�����⡣\n" NOR;
                set_ahinfo(msg);
                return;
        }

        if (p["level"] < victim->query_skill("poison", 1))
        {
                if (! victim->query_temp("has_announce/defense2"))
                {
                        victim->set_temp("has_announce/defense2", 1);
                        victim->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", victim :), victim), 15);
                        msg += "��\n" NOR HIC "$n" HIC "�������Σ���Ȼ��Ц����"
                               "����֮�飬Ҳ�Ź⻪��\n" NOR;
                } else
                        msg += "������$n��Ȼ��û�а����������ϡ�\n" NOR;
                set_ahinfo(msg);
                return;
        }

        if (p["level"] < victim->query_skill("force") / 2)
        {
                if (! victim->query_temp("has_announce/defense3"))
                {
                        victim->set_temp("has_announce/defense3", 1);
                        victim->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", victim :), victim), 15);
                        msg += "��\n" NOR HIC "$n" HIC "��Ц�����üһ��Ȼ" + 
                               (ob == me ? "�����ϴ㶾" : "ʹ�ô㶾����") +
                               "����Щ�����ĵ��ֶ�Ҳ�ҵ�����ǰ��Ū��\n" NOR;
                } else
                        msg += "������$n�������ƺ����޴󰭡�\n" NOR;
                set_ahinfo(msg);
                return;
        }

        victim->affect_by(poison_type, ap);

        msg += "��������ж��ˡ�\n" NOR;
        if (p["level"] < victim->query_skill("force"))
        {
                msg += HIB "$n" HIB "������һ�˿�������Ŀ���أ����еĹ��ƶ�Ȼһ����\n" NOR;
                set_ahinfo(msg);
                return;
        }

        msg += HIR "$n" HIR "�ƺ�һ�������ƶٻ�����������ʹ�ࡣ\n" NOR;
        victim->start_busy(1 + random(2));
        set_ahinfo(msg);
        return;
}

// me hit victim, but poison by victim in ob
void hit_poison(object me, object victim, object ob)
{
        mapping p, ap;
        string msg;
	string poison_type;

        if (! mapp(p = ob->query_temp("daub/poison")))
                return;

	if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
		return;

        if (! p["remain"])
                return;

        if (me->query_temp("armor/hands"))
                return;

        // affect parameter
        ap = allocate_mapping(4);
        ap["level"]    = p["level"] * 7 / 10 + 1;
                
        ap["id"]       = p["id"];
        ap["name"]     = p["name"];
        ap["duration"] = 1;

        if (p["remain"] > p["level"])
        {
                // decrase the remain poison
                p["remain"] -= p["level"];
        } else
        {
                // the poison has run out
                ob->delete_temp("daub");
        }

        msg = HIB "ͻȻ$N" HIB "���û�����Щ����";
        if (p["id"] == me->query("id"))
        {
                if (! me->query_temp("has_announce/defense1"))
                {
                        me->set_temp("has_announce/defense1", 1);
                        me->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", me :), me), 15);
                        msg += "��\n" NOR HIC "$N" HIC "Ĭһ�˹�����Ц�������ø�" +
                               RANK_D->query_rude(victim) + "����Ȼ������ǰ��Ū" +
                               RANK_D->query_self_rude(victim) +
                               "�Ķ�ҩ�������·��ϵĶ�ҩ�������ң�\n" NOR;
                } else
                        msg += "������$N��û�����⡣\n" NOR;
                set_ahinfo(msg);
                return;
        }

        if (p["level"] < me->query_skill("poison", 1))
        {
                if (! me->query_temp("has_announce/defense2"))
                {
                        me->set_temp("has_announce/defense2", 1);
                        me->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", me :), me), 15);
                        msg += "��\n" NOR HIC "$N" HIC "��Ц��������֮��Ҳ��"
                               "�⻪�����������ϴ㶾�Ҿ������ˣ�\n" NOR;
                } else
                        msg += "������$N��Ȼ��û�а����������ϡ�\n" NOR;
                set_ahinfo(msg);
                return;
        }

        if (p["level"] < me->query_skill("force") / 2)
        {
                if (! me->query_temp("has_announce/defense3"))
                {
                        me->set_temp("has_announce/defense3", 1);
                        me->start_call_out(bind((: call_other,
                                __FILE__, "clear_announce", me :), me), 15);
                        msg += "��\n" NOR HIC "$N" HIC "��Ц������Ȼ��������"
                               "�㶾����Щ�����ĵ��ֶ�Ҳ�ҵ�����ǰ��Ū��\n" NOR;
                } else
                        msg += "������$N�������ƺ����޴󰭡�\n" NOR;
                set_ahinfo(msg);
                return;
        }

        me->affect_by(poison_type, ap);

        msg += "��������Щ���\n" NOR;
        if (p["level"] < me->query_skill("force"))
        {
                msg += HIB "$N" HIB "������һ�˿�������Ŀ���أ����еĹ��ƶ�Ȼһ����\n" NOR;
                set_ahinfo(msg);
                return;
        }

        msg += HIR "$N" HIR "�Ų�һ�����ԣ����ƶٻ�����ɫ�ѿ�֮����\n" NOR;
        me->start_busy(1 + random(2));
        set_ahinfo(msg);
        return;
}

void clear_announce(object me)
{
        if (! objectp(me))
                return;

        me->delete_temp("has_announce");
}
