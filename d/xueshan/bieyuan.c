inherit ROOM;

void create()
{
        set("short", "ѩɽ��Ժ");
        set("long", @LONG
�����Ǵ����µķֲ������깱�Ʋִ����ﲻԶ���������
ʥ������Ϊ��ʦ�����ڴ˴�����𷨡�
LONG);
        set("exits", ([
                "east" : "/d/beijing/road5",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1" : 4,
                __DIR__"npc/zhike" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("id") == "seng bing"
           && dir == "east")
                return 0;

        return ::valid_leave(me, dir);
}
