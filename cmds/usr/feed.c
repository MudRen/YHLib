// feed.c �����

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        int lvl;

        if (me->ban_say(0))
                return 0;

        if (! arg)
                return notify_fail("��Ҫ���ĸ���ҽ���Ȧ��\n");

        if (! objectp(ob = find_player(arg)) || ! me->visible(ob))
                return notify_fail("��Ҫ���ĸ���ҽ���Ȧ��\n");

        if (me == ob)
                return notify_fail("�������ˮ��\n");

        if (wiz_level(me) < wiz_level(ob))
                return notify_fail("�������ˮƽ��û����ô�ߡ�\n");

        lvl = me->query_skill("feed-power", 1);
        if (! lvl)
                return notify_fail("�����ѧ�����������˵��\n");

        if (lvl < 50)
                return notify_fail("�������ˮƽ̫��޷�ʩչ������\n");

        if (lvl < 300 && environment(ob) != environment(me))
                return notify_fail("�������ˮƽ���ޣ��޷�ʩչ������ǧ��֮�⣡\n");

        if (environment(ob) == find_object("/d/city/zhujuan"))
                return notify_fail("����������Ȧ�����ء�\n");

        if (! environment(ob)->is_chat_room() && wiz_level(me) < 1)
                return notify_fail("�������ڵĵص���������ʩչ������\n");

        if (! interactive(ob))
                return notify_fail("���˲������ϣ�������֮��\n");

        if (query_idle(ob) < 120)
                return notify_fail("�������ھ������أ��������ɡ�\n");

        if (ob->query_temp("on_baitan"))
                return notify_fail("�������������⣬���Ǳ�ȥ���š�\n");

        if (me->query("jing") < 50)
                return notify_fail("��ľ���̫�����ʩչ��һ�����񹦡�\n");

        if (me->query("learned_points") + 10 > me->query("potential"))
                return notify_fail("���Ǳ�ܲ������޷�ʩչ��һ�����񹦡�\n");

        me->receive_damage("jing", 50);
        me->add("learned_points", 10);

        message_vision(HIM "$N" HIM "���������дʣ�����Ԫ˧������������Ϸ���һͷ��\n", me);
        if (! wizardp(ob) && (random(lvl * lvl) + lvl * lvl < ob->query("combat_exp") ||
            ob->query("combat_exp") >= 50000))
        {
                write("û���κ�Ч������������������ɣ�\n");
                return 1;
        }

        switch(random(4))
        {
        case 0:
                message_vision(HIM "����ֳ�������ƣ�����Ԫ˧�������£�һ������"
                               HIM "$N" HIM "����Ц����������ȥ�ˡ�\n" NOR,
                               ob);
                break;
        case 1:
                message_vision(HIM "����Ԫ˧������һ�������У�һ��ץס$N"
                               HIM "���ȵ����ߣ����Ǽ����������������ȥ��\n" NOR,
                               ob);
                break;
        case 2:
                message_vision(HIM "����Ԫ˧����ææ������������������" +
                               ob->name() + HIM "���϶������ˣ�$N"
                               HIM "һ������æ��������ƨ�ɺ���ߵߵ����ˡ�\n" NOR,
                               ob);
                break;
        default:
                message_vision(HIM "��ͨһ�£�ֻ������Ԫ˧������ˤ��������$N" +
                               HIM "�̲�ס����һЦ��Ԫ˧��ŭ�����üһ���������\n"
                               "һ���������ֻ���ҽ�������$N" HIM "��������Զȥ��\n" NOR,
                               ob);
                break;
        }

        ob->move("/d/city/zhujuan");
        message("vision", "ֻ������ͨ��һ����" + ob->name() +
                          "��������Ȧ�������������ź��ࡣ\n",
                environment(ob), ob);
        write(HIC "�������󷨳ɹ��ˣ�" + ob->name(1) +
              HIC "���ڽ���Ȧ��ȥ��\n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                              me->name(1) + HIM "ʩչ����󷨣�" +
                              ob->name(1) + HIM "����Ȧ������������˯���ѡ�");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : feed <���>

���������ڷ����������ó������񹦣���ô����ʹ������ָ��
��������ͽ���Ȧʵϰ��ÿʹ��һ������󷨶���ķ�ʮ��Ǳ��
��һЩ����
 
HELP );
        return 1;
}
