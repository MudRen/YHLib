#include <ansi.h> 
inherit ROOM;

int do_study(string arg);

void create()
{
	set("short", NOR + WHT "������" NOR);
	set("long", @LONG
�����Ƿ������µĵ������ҡ�������С��ȴҲ�����ȫ��ʯ
��ʯ�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ�����
�ƺ��ܾ���ǰ����������ס�������е�ʯ�� (table)��ƽ����һ
�鱡����ʯ�壬����������Щʲô��
LONG);
	set("exits", ([
		"up" : __DIR__"beilin2",
	]));
	set("objects",([
		"/clone/book/book-stone" : 1,
	]));
	set("item_desc", ([
		"table" : WHT "����һ�����ʯ��ɵ�ʯ��"
                          "���������Щ��ֵ�ͼ�Ρ�\n" NOR,
	]));
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}

int do_study(string arg)
{
	object me;
        string msg;

	me = this_player();

	if (arg != "table")
		return notify_fail("��Ҫ��ʲô��\n");

	if ((int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	me->receive_damage("jing", 10 + random(40));

        if (me->query("jing") < 0)
	{
                me->unconcious();
		return 1;
	}

	msg = HIY "��ר�ĵ��ж�ʯ���ϵĹŹ�ͼ�Ρ�\n" NOR;

	switch (random(5)) 
	{
	    case 0:
		if ((int)me->query_skill("finger", 1) < 100)
		{
			me->improve_skill("finger", 1 + random(me->query("int")));
			msg += "�����ʯ����ĥ��һ�ض����ƺ���ָ���е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}
                break;

	    case 1:
		if ((int)me->query_skill("claw", 1) < 100)
		{
			me->improve_skill("claw", 1 + random(me->query("int")));
			msg += "�����ʯ����ĥ��һ�ض����ƺ���צ���е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}
                break;

	    case 2:
		if ((int)me->query_skill("strike", 1) < 100)
		{
			me->improve_skill("strike", 1 + me->query("int"));
			msg += "�����ʯ����ĥ��һ�ض����ƺ����Ʒ��е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}
                break;

	    case 3:
		if ((int)me->query_skill("cuff", 1) < 100)
		{
			me->improve_skill("cuff", 1 + random(me->query("int")));
			msg += "�����ʯ����ĥ��һ�ض����ƺ���ȭ���е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}
                break;

	    case 4:
		if ( (int)me->query_skill("hand", 1) < 100)
		{
			me->improve_skill("hand", 1 + random(me->query("int")));
			msg += "�����ʯ����ĥ��һ�ض����ƺ����ַ��е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}
	}

	if (! me->query_temp("stone_learned"))
		msg += HIY "�����ʯ����ĥ��һ�ض�������������˵���Ѿ�̫"
                       "��ǳ���ˡ�\n" NOR;

        write(msg);
	return 1;
}
