inherit ROOM;

void create()
{
        set("short", "������Ϊ��");
        set("long", @LONG
����ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴�����
ǰ�������Ϲ��š������á������Ҷ���кܿ���ȴûʲô
���裬��ǽ�������ѽ��Ρ�������������Ⱥ���¼���ͽ�ĵط�
���������ҡ�
LONG);
        set("exits", ([
            	"north" : __DIR__"buwei2",
            	"south" : __DIR__"qunxianguan",
            	"west"  : __DIR__"garden",
            	"east"  : __DIR__"buwei3",
        ]));
        set("objects", ([
             	__DIR__"npc/dayou" : 1,
		"/clone/quarry/hou" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir == "south" ||
            ! objectp(guard = present("lu dayou", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
