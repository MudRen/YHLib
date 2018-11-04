#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ʯ");
        set("long",
                "��ʯ��Զ����ֻ���ƺ���ã�����վ�������������һ��������"
                "ǧ���һ�ɴ�ý�ɽ������ʯ��������ɽ�壬���������ͱڣ���"
                "Ԩ���ɡ�");
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));

	set("outdoors", "mingjiao");
	setup();
        (CLASS_D("ultra") + "/huoshan")->come_here();
}

string long()
{
        object ob;
        string msg;

        msg = query("long");
        if (! objectp(ob = present("huo shan", this_object())))
                return sort_string(msg, 64, 4);

        if (! ob->is_fighting())
                msg += "һ������վ��ʯ��ң���ƺ��������Ķ��������"
                       "�����������";
        else
                msg += "ֻ��һ��������" +
                       (ob->is_fighting(this_player()) ? "��" : "��") +
                       "��ս�����������ô�ʯ�������ѡ�";

        return sort_string(msg, 58, 4);
}

void init()
{
	add_action("do_tiao", "tiao");
	add_action("do_tiao", "jump");
}

int do_tiao(object me)
{
	me = this_player();
	message_vision(HIY "\n$N" HIY "������Ƭ���͵�����Ԩ"
                       "���£���ӰԽƮԽС��\n\n" NOR, me);

	if (me->query_dex() > 25)
	{
		me->move(__DIR__"gudi1");
	} else
        if (me->query_dex() > 20)
	{
		me->move(__DIR__"gudi1");
		me->unconcious();
	} else
	{
		me->move(__DIR__"gudi1");
		me->die();
	}
	return 1;
}

