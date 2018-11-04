#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����̼ұ������䳡�������ĳ�����������ϸϸ�Ļ�������
���ʺ����䡣�����м����̼ұ��ĵ����������䡣���䳡������
���ż���ľ׮(muzhuang)����Χ�����м���ɳ��(shakeng)��
LONG);
        set("item_desc", ([
                "shakeng"  : WHT "ɳ������Щ�ҽ�����ϰ�Ṧ����Ҳ��"
                             "����(tiao)��ȥ���ԡ�\n" NOR,
                "muzhuang" : WHT "����ľ׮���в��ٻ���(jida)���ĺ�"
                             "����\n" NOR,
        ]));

	set("exits", ([
		"west"  : __DIR__"shang_qgc",
	]));
	setup();
}

void init()
{
        add_action("do_jida", "jida");
        add_action("do_tiao", "tiao");
}

int do_jida(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if (! living(me) || arg != "muzhuang")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��������б�����ľ׮��ȥ�����˰��췢�ֺ��޳�Ч��\n");

        if ((int)me->query_skill("bagua-quan", 1) < 30
           || (int)me->query_skill("bagua-zhang", 1) < 30)
                return notify_fail("������˰��죬�ƺ�ûʲôЧ���������ǰ���ȭ�Ƶȼ�̫"
                                   "�͵�Ե�ʡ�\n");

        if ((int)me->query_skill("bagua-quan", 1) >= 120
           && (int)me->query_skill("bagua-zhang", 1) >= 120)
                return notify_fail("�����ľ׮������һ��������������Ѿ����������ʲô"
                                   "�ˡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("�������۵ø첲��̧�������ˣ���������Ϣһ����ɣ�\n");

        me->receive_damage("qi", 30);

        if (me->can_improve_skill("bagua-zhang")
           && (int)me->query_skill("bagua-zhang", 1) < 120)
                me->improve_skill("bagua-zhang", me->query("con") * 2);

        if (me->can_improve_skill("bagua-quan")
           && (int)me->query_skill("bagua-quan", 1) < 120)
                me->improve_skill("bagua-quan", me->query("con") * 2);

        me->start_busy(random(2));
        message_vision(WHT "\n$N" WHT "վ������һ��һȭ����ľ׮����������\n" NOR, me);
        write(HIC "���ڻ�������������˲��١�����ȭ�������������Ʒ��������š�\n" NOR);
        return 1;
}

int do_tiao(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if (! living(me) || arg != "shakeng")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("dodge", 1) < 30
           || (int)me->query_skill("bagua-bu", 1) < 30)
                return notify_fail("�����������ɳ����ȥ�����һ�����ص�ˤ���˿��С�\n");

        if ((int)me->query_skill("dodge", 1) >= 120
           && (int)me->query_skill("bagua-bu", 1) >= 120)
                return notify_fail("����ɳ����Χ����һ�����������������ϰ�Ѿ�ûʲô���ˡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("�������۵ýŶ�̧�������ˣ���������Ϣһ����ɣ�\n");

        me->receive_damage("qi", 30);

        if (me->can_improve_skill("dodge")
           && (int)me->query_skill("dodge", 1) < 120)
                me->improve_skill("dodge", me->query("con") * 2);

        if (me->can_improve_skill("bagua-bu")
           && (int)me->query_skill("bagua-bu", 1) < 120)
                me->improve_skill("bagua-bu", me->query("con") * 2);

        me->start_busy(random(2));
        message_vision(WHT "\n$N" WHT "����һ��������쬡���һ��������ɳ�ӣ����ŷ���һ��"
                       "�����˻�����\n" NOR, me);
        write(HIC "��ԡ����Բ��������������Ṧ�������µ���⡣\n" NOR);
        return 1;
}
