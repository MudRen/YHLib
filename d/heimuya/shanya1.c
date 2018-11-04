inherit ROOM;

void create()
{
        set("short", "�ɵµ����");
        set("long", @LONG
�˴����Ƹ��ʣ����Ǻ�ľ���ϣ�����վ����������̵ĵ�
�ӡ����ԵĿ������д��֣������ǡ��ĳ���¡��������ǡ���
��Ӣ����������Ͽ��š����¹������ĸ�����֡�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"south" : __DIR__"shanya2",
            	"north" : __DIR__"chengdedian",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
                CLASS_D("riyue") + "/wang" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object wang;

        if (dir != "north"
           || ! objectp(wang = present("wang cheng", this_object())))
                return ::valid_leave(me, dir);

        return wang->permit_pass(me, dir);
}
