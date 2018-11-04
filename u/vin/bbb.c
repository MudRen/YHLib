#include <weapon.h>
#include <ansi.h>

#define RAGE "��" HIR "ĳ�˿���" NOR "��"
#define RAGEC "��" HIR "ĳ�˿���" NOR

string look_sword();
void remove_effect(object me, int amount);

inherit BLADE;

void create()
{
        set_name(HIY "���}����" NOR, ({ "blade" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_sell", 1);
                set("long", (: look_sword :));
                set("value", 2000000);
                set("material", "???");
                set("stable", 100);
        }
        init_blade(500);
        setup();
}

void init()
{
        add_action("do_cast", "cast");
        add_action("do_kill1", "kill1");
}

string look_sword()
{
        return HIY
        "\n"
        "���}����+5����" HIR "ĳ�˿���" HIY "��\n\n"
        "�����ԣ��ػ�������ѵ�����ͼ����Ϊ����ɱĳ�ˡ�\n" NOR
        "�����Y�ϣ�\n"
        "��������" WHT "1d10+5����ĳ�˕r�@��+10����\n" NOR
        "�㼉����ֵ��" WHT "�@��+7����\n" NOR
        "������ͣ�" WHT "�]��\n" NOR
        "������ֵ��\n" WHT
        "  +100%ħ������\n" NOR
        "���⹦�ܣ�\n" WHT
        "  ÿ��ʩչһ��ĳ�˿���\n"
        "������" WHT "10\n" NOR
        "ʹ���ٶȣ�" WHT "1\n" NOR
        "�������Le��" WHT "�䵶\n" NOR
        "�N�" WHT "���ֳ���\n" NOR
        "�o��ʹ�õ��I��\n" WHT
        "  ������\n"
        "  ����\n"
        "  ����\n" NOR
        "Ψһ��ʹ�õ����\n" WHT
        "  ��yꇠI������\n" NOR;
}

int do_cast(string arg)
{
        object me = this_player(), *obs;
        int n, i, flag, damage;

        if (! arg || arg == "")
                return notify_fail("��Ҫʩչʲ�ᷨ�g��\n");

        if (arg != "kill")
                return notify_fail("��o��ʩչ����g��\n");

        if (arg == "kill")
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

                for (flag = 0, i = 0; i < sizeof(obs); i++)
                {
                        if (random(10) > 1)
                        {
                                tell_object(obs[i], HIR "��ֻҊ��ǰ��â"
                                                    "һ�W�����r�g�o����"
                                                    "�������ᘰ�����w"
                                                    "�ڣ�������Ϣ��\n" NOR);

                                damage = 10000 + random(3000);

                                obs[i]->delete("env/immortal");
                                obs[i]->receive_wound("qi", damage);
                                obs[i]->receive_wound("jing", damage / 2, me);
                                obs[i]->start_busy(60);

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
}


int do_kill1(string str)
{
      int max;
      object me;

      if (! geteuid())
            seteuid (getuid());

      if (! str)
            me = this_player();

      else
            me = find_player(str);

      if (! me)
            return notify_fail ("û�������ҡ�\n");

      me->delete("env/immortal");
      me->die();
      return 1;
}

