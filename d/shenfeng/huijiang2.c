inherit ROOM;

void create()
{
        set("short", "���׶���ԭ");
        set("long", @LONG
���������Ͻ������صĵ��ƺ����򣬾��γ��Ͻ��ѵ�һ��
��СƬ��ԭ������ɽ��ס�˱������磬�������ḻ���۾���
���ٹ��������ˡ���˹����Ҳ�����˵ط���������
LONG);
        set("outdoors", "gaochang");

        set("exits", ([
            	"northup" : __DIR__"huijiang1",
            	"southdown" : __DIR__"huijiang3",
        ]));
        set("objects", ([
                __DIR__"npc/hasake"  : 1,
                "/clone/quarry/yang" : 3,
        ]));
        set("quarrys", ([
                "yang"  : 100000,
                "gou"   : 100000,
                "lang"  : 80000,
                "lang2" : 50000,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
