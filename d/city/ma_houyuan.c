inherit ROOM;

void create()
{
        set("short", "��ׯ��Ժ");
        set("long", @LONG
��������ׯ�ĺ�Ժ�������ʹ�Ժ��ࡣ������Ȼ�ۼ���
�����ؤ����Ժ��ȴ�Ǵ����úܸɾ�������һ�����˼ҵ�ͥ
԰һ�㡣ͨ����������ǰ�����ż�����ؤ��
LONG);
        set("outdoors", "city");
        set("exits", ([
                "north" : __DIR__"ma_zhengting",
                "south" : __DIR__"ma_dayuan",
        ]));
        set("no_clean_up", 0);
	set("objects", ([
		"/d/gaibang/npc/6dai" : 1 + random(2),
		"/d/gaibang/npc/7dai" : random(2),
                CLASS_D("gaibang") + "/quan" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "north"
           || ! objectp(guard = present("quan guanqing", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}


