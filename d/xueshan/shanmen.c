inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����µ�ɽ�ţ���ǰ�����ﲻ���Ľ��㳯ʥ����ͽ
���е�����������˿�����ϵĲ�˿��ɽ��ǰվ�˸��ֳַ�����
���ײ���ά�����򣬶�����һ����ʯ���̳ɵ�ɽ·��
LONG);
        set("outdoors", "xueshan");
        set("exits", ([
                "north"    : __DIR__"guangchang",
                "eastdown" : "/d/xuedao/nroad4",
        ]));
        set("objects", ([
                CLASS_D("xueshan") + "/gelunbu": 1,
                "/d/wudang/npc/guest": 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object glb;

        if (dir != "north" ||
            ! objectp(glb = present("ge lunbu", this_object())))
                return ::valid_leave(me, dir);

        return glb->permit_pass(me, dir);
}
