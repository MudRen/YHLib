#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name(NOR + CYN "��ɳ��Ӱ" NOR, ({ "hansha sheying", "han", "sha", "hansha", "sheying" }) );
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("long", CYN "�����嶾�̵����Ű�������ɳ��Ӱ����������һ����\n"
                                "���������������䡣���м���һ������С���У�ֻ\n"
                                "Ҫ������һ��(shot)�Ϳ��Է����ϸ��ţë�Ķ��롣\n" NOR) ;
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "�Թԣ��⡭�ⲻ�ǺΡ������ġ���");
                set("zhen", 10);
                set("material", "iron");
                set("armor_prop/armor", 3);
                set("stable", 100);
        }
        setup();
}

void init()
{
        add_action("do_shot", "shot");
}

int do_shot(string arg)
{
        object me, ob, target;
        int myskill, tgskill;
        int mylev, damage;
        string fam;

        me = this_player();

        if (environment(me)->query("no_fight"))
                return notify_fail ("���ﲻ׼ս����\n");

        if (me->query_temp("armor/waist") != this_object())
                return notify_fail("�����ȵý���ɳ��Ӱװ�������䡣\n");

        if (! arg)
                return notify_fail("�����˭���京ɳ��Ӱ��\n");

        if (! objectp(target = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if (target->query("id") == me->query("id"))
                return notify_fail("����ɱ�Լ���\n");

        if (! me->is_fighting(target))
                return notify_fail("��ֻ����ɱս���еĶ��֡�\n");

        if (! target->is_character() || target->is_corpse())
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if (me->is_busy())
                return notify_fail("����æ���ġ�\n");

        if (this_object()->query("zhen") < 1)
                return notify_fail("�����еĶ����Ѿ�����ˡ�\n");

        if (! objectp(ob = present("hansha sheying", me)))
                return notify_fail("��û�����ֶ�����\n");

        myskill = me->query_skill("hansha-sheying", 1) + me->query_skill("dodge", 1);
        tgskill = target->query_skill("dodge");
        mylev = me->query_skill("hansha-sheying", 1);

        if (mylev <= 50)
                return notify_fail("��ĺ�ɳ��Ӱ�����������޷�ʹ�ô���Ʒ��\n");

        this_object()->add("zhen", -1);
        message_vision(HIW "\n$N" HIW "һ����Ц�����ֲ������������һ����ֻ��"
                       "��һ�������͡����ƿ�����\n" NOR, me, target);
        me->start_busy(2 + random(2)) ;

        if (random(myskill) < tgskill)
	{
                message_vision(HIY "$n" HIY "���һ�����͵�һ�����ذδ�����"
                        "�����������ߣ��㿪��$N" HIY "�Ķ��룡\n\n" NOR,
                        me, target);
	} else
	{
                message_vision(HIR "$n" HIR "����������������ϸ��ţë�Ķ���"
                               "����һ�����ɲҺ�������\n\n" NOR, me, target);

                target->affect_by("sha_poison",
                               ([ "level" : me->query("jiali") + random(me->query("jiali")),
                                  "id"    : me->query("id"),
                                  "duration" : mylev / 50 + random(mylev / 20) ]));

                tell_object (target, HIB "��ֻ�������ϡ���ǰһʹ����������"
                                     "���Ѱ���\n" NOR);

                damage = mylev * 4 - (target->query("max_neili") / 10);
                if (damage < 100 ) damage = 100;
                if (damage > 800 ) damage = 800;
                target->receive_wound("qi", damage) ; 
                target->start_busy(4);
        }

        if (! target->is_killing(me))
		target->kill_ob(me);

        return 1;
}
