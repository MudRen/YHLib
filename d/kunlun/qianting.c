inherit ROOM;

void create()
{
	set("short", "ǰ��");
        set("long",@long
�����������������ܴ��ߣ�ʮ�ֵļ���׳�������ڰڼ���
�߱����Σ�һ�Ű������������ǽӴ����˵ĵط�������Ͷ���
Ҳ�ǿ�����������ЪϢ������һ������ͨ����档
long);
        set("exits",([
		"north" : __DIR__"pingfeng",
		"south" : __DIR__"shilu1",
		"west" : __DIR__"wlang01",
		"east" : __DIR__"elang01",
	]));

        set("objects",([
                CLASS_D("kunlun") + "/xihuazi" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object xi;

        if (dir != "south" ||
            ! objectp(xi = present("xi huazi", this_object())))
                return ::valid_leave(me, dir);

        return xi->permit_pass(me, dir);
}