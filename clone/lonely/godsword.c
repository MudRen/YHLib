#include <weapon.h>
#include <ansi.h>

#define RAGE "��" HIR "�R���T֮ŭ" NOR "��"
#define RAGEC "��" HIR "�R���T֮ŭ" NOR

#define SHIELD "��" HIB "��ɽ�_�ߵ��o��" NOR "��"
#define SHIELDC "��" HIB "��ɽ�_�ߵ��o��" NOR

string look_sword();
void remove_effect(object me, int amount);

inherit SWORD;

void create()
{
        set_name(HIY "���}�L��" NOR, ({ "long sword", "sword" }));
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("no_sell", 1);
                set("long", (: look_sword :));
                set("value", 2000000);
                set("no_sell", "Oh��My god��");
                set("material", "???");
                set("stable", 100);
        }
        init_sword(500);
        setup();
}

void init()
{
        add_action("do_cast", "cast");
}

string look_sword()
{
        return HIY
        "\n"
        "���}�L��+5����" HIR "�T�����֜" HIY "��\n\n"
        "�@���L�����˱����ɰ��y���T�⣬����������ڣ��o�h�o�У����Ʊ�\n"
        "�FƬ�㡣���Ǯ����ָ���|��������r���ܸе�һ�z�̹ǵı������@\n"
        "�r�������l�X�����������ġ��T�����֜�T���1039 DR ���T������\n"
        "�۠����µ�һλ���A���������r�۠������ܵ���F�˵ć����L�_����\n"
        "֮�ã���ݔ���Y�ĵ�·���Д࣬��ʿ���˂�����L�ڵò����a�o����\n"
        "��ʿ����䣬��˹������R�������ڑ����Ѕs�����˾�Ԯ���t���Ĺ�\n"
        "����ͬ�r������Ҳ�ڲ�ͣ�����T������������ƽ�����M���˂��\n"
        "�ϵ��ŷ����T�񣬵ȴ�����o�c���������۠��������1042 DR ����\n"
        "�F�˹��ף�ͬ�r˹������R����һƬ�U�棬�@�ф�Ҳ��֪��ۙ��\n\n"
        "�ڂܿˡ��ڂ�˹��һλ������}��ʿ��������������������������\n"
        "�Q���˂��Q���ǡ��p���֡����s��֪���ĺܴ�һ���������ǁ������\n"
        "���䄦��һ�����������ǵľư��У�һλ����İ��˱I�����M���ķQ\n"
        "̖�������l���������mȻ�ڂܿˡ��ڂ�˹Ӣ���Ƒ�Ҳ�������@λ\n"
        "�����İ��˱I����������Ȼ�����^ǰ���æ�Ĵ�Ⱥ�t��ʿ���F�Ĺ�Ӷ\n"
        "�������ֳ����߉K�����@�ф�Ҳ��Ӷ���^�I��������Ʒȡ�ߡ�\n\n" NOR
        "�����Y�ϣ�\n"
        "��������" WHT "1d10+5������������а��ꇠI�Ĕ��˕r�@��+10����\n" NOR
        "�㼉����ֵ��" WHT "�@��+7����\n" NOR
        "������ͣ�" WHT "�]��\n" NOR
        "������ֵ��\n" WHT
        "  +15%ħ������\n"
        "  +50%���俹��\n"
        "  �����¹����Ļ����ʙz��+10����\n" NOR
        "���⹦�ܣ�\n" WHT
        "  ÿ��ʩչһ���R���T֮ŭ\n"
        "  ÿ��ʩչ�ɴ���ɽ�_�ߵ��o��\n"
        "  ÿ��ʩչ����Ӣ�ۚ��\n"
        "  �����ߌ�����һָ/�������/���Ȼ�/�֑�֮��/�o����ӡ����\n"
        "  ����Ŀ������15%�C����Ŀ����裬���r10݆\n"
        "  ����Ŀ������50%�C���Գ����ߞ����İl��һ��3d6�Ļ���\n" NOR
        "������" WHT "10\n" NOR
        "ʹ���ٶȣ�" WHT "1\n" NOR
        "�������Le��" WHT "���̈́�\n" NOR
        "�N�" WHT "���ֳ���\n" NOR
        "�o��ʹ�õ��I��\n" WHT
        "  ������\n"
        "  ����\n"
        "  ����\n" NOR
        "Ψһ��ʹ�õ����\n" WHT
        "  ��yꇠI������\n" NOR;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
	n = 3 + random(16);

        if (random(100) < 15 && living(victim))
	{
                victim->unconcious();
        	return HIR "���r�gֻҊ$N" HIY "���}�L��" HIR"��â��"
                       "�q��$n" HIR "�D�Xһꇻ�ѣ��\n" NOR;
	} else
        if (random(100) < 50)
	{
	        victim->receive_wound("qi", n * 100, me);
	        victim->receive_wound("jing", n * 50, me);
        	return HIR "ֻҊ$N" HIY "���}�L��" HIR"���ⶸȻ����"
                       "��" + chinese_number(n) + "�����򣬱M������"
                       "$n" HIR "ȫ��\n" NOR;
	}
}

int do_cast(string arg)
{
        object me = this_player(), *obs;
        int n, i, flag, damage;

        if (! arg || arg == "")
                return notify_fail("��Ҫʩչʲ�ᷨ�g��\n");

        if (arg != "rage" && arg != "shield")
                return notify_fail("��o��ʩչ����g��\n");

        if (arg == "rage")
        {
	        me->clean_up_enemy();
	        obs = me->query_enemy();

	        if (! me->is_fighting())
        	        return notify_fail("��ֻ���ڑ��Y�в���ʩչ"
                                           RAGE "��\n");

	        if (me->is_busy())
        	        return notify_fail("��F������æ���]�Еr�g"
                                           "ʩ��" RAGE "��\n");

	        message_vision(HIW "\n$N" HIW "ʩ��" RAGEC + HIW "��"
                               "�������b�����ȵ�ķ�������ɡ�̩��"
                               "���ա����ء�\n\n" NOR, me);
	        me->start_busy(5);

        	for (flag = 0, i = 0; i < sizeof(obs); i++)
        	{
                	if (random(10) > 3)
                	{
                                tell_object(obs[i], HIR "��ֻҊ��ǰ��â"
                                                    "һ�W�����r�g�o����"
                                                    "�������ᘰ�����w"
                                                    "�ڣ�������Ϣ��\n" NOR);

                		damage = 1000 + random(3000);
                		obs[i]->receive_wound("qi", damage);
                        	obs[i]->receive_wound("jing", damage / 2, me);

	                        message("vision", HIY + obs[i]->name() +
                                                  HIY "ֻҊ��ǰ��âһ�W"
                                                  "�����r�g�o���⾀����"
                                                  "�ᘰ�����w�ڣ�����"
                                                  "��Ϣ��\n\n" NOR,
                                                  environment(me),
                                                  ({ obs[i] }));
                        	flag = 1;
                	} else
                	{
                        	tell_object(obs[i], HIC "�㷨�g�����ʙz��"
                                                    "�ɹ������_��" RAGEC +
                                                    HIC "���Ĺ�����\n" NOR);
                	}
        	}
        	if (! flag) 
                	message_vision(HIC "Ȼ���]���κ����ܵ�$N" RAGEC +
                                       HIC "����Ӱ�졣\n" NOR, me, 0, obs);
	        return 1;
	}

        if (arg == "shield")
        {
        	if ((int)me->query_temp("shieldc"))
                	return notify_fail("���ѽ�ʩչ��" SHIELD "��\n");

	        n = 500;

	        message_vision(HIW "\n$N" HIW "ʩ��" SHIELDC + HIW "��"
                               "�������b��������˹������������Ἢ��"
                               "��Ī���_����\n\n" NOR, me);

	        me->add_temp("apply/armor", n);
        	me->set_temp("shieldc", 1);

	        me->start_call_out((: call_other, __FILE__, "remove_effect",
                                      me, n :), n);

	        return 1;
	}
}

void remove_effect(object me, int n)
{
        if (me->query_temp("shieldc"))
       	{
               	me->add_temp("apply/armor", -n);
               	me->delete_temp("shieldc");
               	tell_object(me, "���" SHIELD "ʩչ�ꮅ��\n");
       	}
}