// punisher.c

#include <ansi.h>

inherit NPC;

void setup()
{
        add_temp("apply/attack", 300);
        add_temp("apply/defense", 300);
        add_temp("apply/damage", 1000);
        add_temp("apply/unarmed_damage", 1000);
        add_temp("apply/armor", 3000);
        ::setup();
        set_heart_beat(1);
}

void init()
{
        add_action("do_halt", "halt");
}

int do_halt()
{
        object me;

        if (this_player() == query_temp("punish_ob"))
        {
                write(HIW "����" + name() + "ŭ�ȵ�������ͽ�����ߣ���\n" NOR);
                return 1;
        }

        return 0;
}

void receive_damage(string type, int amount, object who)
{
        ::receive_damage(type, 1 + amount / 100, who);
}

void receive_wound(string type, int amount, object who)
{
        ::receive_wound(type, 1 + amount / 100, who);
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 200 + random(200), me);
        me->set("neili", me->query("max_neili"));
        return HIR "$N" HIR "һ��ͻ������Ȼ��$n" HIR "����δ�ţ�����δ"
               "������ʽ��һ��֮�£���Ȼ�ܴ���\n" NOR;
}

void fight_ob(object ob)
{
	if (is_fighting(ob))
		return;

        if (ob != query_temp("punish_ob") &&
            ! is_fighting(ob))
        {
                message_vision(CYN "$N" CYN "��$n" CYN "��Ц����������"
                               "�������Ż��������������\n" NOR,
			       this_object(), ob);
		if (! ob->is_busy())
			ob->start_busy(5);
        }

        ::fight_ob(ob);
	if (! is_killing(ob->query("id")))
        	kill_ob(ob);
}

int accept_fight(object ob)
{
        message_vision(HIW "\n$N" HIW "���˿�$n" HIW "����Цһ������Ҳ"
                       "����\n" NOR, this_object(), ob);
        return 0;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        command("say �٣�������");
        return 1;
}

void start_punish(object ob, string fam)
{
        set_temp("punish_ob", ob);
        set_temp("punishing_fam", fam);
        move(environment(ob));

        message_vision(HIW "ֻ��$N" HIW "���˹���������$n" HIW
                       "����Цһ����\n" NOR, this_object(), ob);

        if (! this_object()->chat_punish())
        {
                // no chat for punish, use default
                command("chat " + ob->name(1) + "�㱳��ʦ�ţ������Ҿ�Ϊ"
                        + fam + "����Ż��������书�������·��");
        }
        command("follow " + ob->query("id"));

        if (environment(ob)->query("no_fight"))
        {
                tell_object(ob, HIW "�㿴��" + name() + HIW "׷��������"
                                "���һ������æת�����ߡ�\n" NOR);

                message("vision", HIW "ֻ��" + ob->name() + HIW "����" +
                                  name() + HIW "����ɫ��䣬������ŵ�"
                                  "ת�����ߡ�\n\n" NOR + HIR + name() +
                                  HIR "��Цһ�����ȵ�������ͽ�������ӣ�"
                                  "���������׷����ȥ��\n" NOR,
                                  environment(ob), ({ ob }));

                ob->move("/d/city/guangchang");
                move("/d/city/guangchang");
                tell_object(ob, HIR "���⡭�������������Ϥ�������ĵ�"
                                "һ�ᣬת���������ȵ�������������������"
                                "���ƣ����ɣ�����\n" NOR);

                message("vision", HIW "ֻ��" + ob->name() + HIW "�Ż���"
                                  "�ŵ����˹�����ȴ����һ�˽������\n"
                                  NOR, environment(ob), ({ ob }));
        }

        command("yun powerup");
        kill_ob(ob);
}

void punish_ob(object ob)
{
        string fam;

        remove_enemy(ob);
        if (living(ob))
                ob->unconcious();

        message_vision(HIY "$N" HIY "һ����ȣ���Ȼһָ������$n" HIY "��̴"
                       "�д�Ѩ֮�ϡ�\n\n" NOR + CYN "$N" CYN "˵�������շ�"
                       "ȥ$n" CYN "�����书����$p��������$p������" NOR,
                       this_object(), ob);

        fam = query_temp("punishing_fam");
        ob->add("detach/times", 1);
        ob->add("detach/" + fam, 1);
        if (ob->add("betrayer/times", -(int)ob->query("betrayer/" + fam)) < 1)
                ob->delete("betrayer");
        else
                ob->delete("betrayer/" + fam);

        ob->skill_expell_penalty();

        if (is_fighting())
        {
                // Am I in fighting now ?
                message_vision(HIW "$N" HIW "��������ߣ����¼�λ���µ�"
                               "���������Ҷ������㣡\n" NOR,
                               this_object());
        }
        message_vision(HIY "$N" HIY "Ʋ��$n" HIY "����Цһ�����漴�ﳤ��"
                       "ȥ��\n" NOR, this_object(), ob);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                            ob->name(1) + HIM "��Ϊ����ʦ�ţ���" +
                            name() + HIM "��ȥһ���书��");
        destruct(this_object());
        return;
}

int attack()
{
        object ob;

        if (objectp(ob = query_temp("punish_ob")) &&
            ! living(ob) &&
            environment(ob) == environment())
        {
                punish_ob(ob);
                return 1;
        } else
                return ::attack();
}

void unconcious()
{
        string fam;
        object ob;

        if (objectp(ob = query_last_damage_from())
           && userp(ob))
        {
        	fam = query_temp("punishing_fam");
        	ob->add("detach/times", 1);
        	ob->add("detach/" + fam, 1);

        	if (ob->add("betrayer/times", -(int)ob->query("betrayer/" + fam)) < 1)
                	ob->delete("betrayer");
        	else
                	ob->delete("betrayer/" + fam);

	        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                                      HIM "����ʦ�ź�ɱ����ǰ��׷ɱ��" + name() +
                                      HIM "�����ں������ǡ�");
        }
        ::die();
}

void scan()
{
        object ob;

        if (! environment())
        {
                destruct(this_object());
                return;
        }

        if (! objectp(ob = query_temp("punish_ob")) ||
            environment(ob) != environment() ||
            environment(ob)->query("no_fight"))
        {
                message_vision(HIW "$N" HIW "��ס��ʽ�����һ�����漴"
                               "ת����ȥ��\n" NOR, this_object());
                destruct(this_object());
                return;
        }

        if (! living(ob))
        {
                punish_ob(ob);
                return;
        }

        if (! is_fighting(ob))
                fight_ob(ob);

        ::scan();
}
