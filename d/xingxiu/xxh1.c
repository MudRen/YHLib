inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ
���ն񡣶���ʯ����һ���ѷ�ͨ��һ��ɽ����
LONG);
        set("exits", ([
             	"north"   : __DIR__"xxh2",
             	"southup" : __DIR__"tianroad2",
             	"westup"  : __DIR__"tianroad3",
        ]));
        set("objects", ([
                CLASS_D("xingxiu") + "/zhaixing" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}


