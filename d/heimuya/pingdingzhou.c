inherit ROOM;

void create()
{
    	set("short", "ƽ����");
    	set("long", @LONG
ƽ�����ںӱ�ʡ���ڣ�ƽ�����ݸ����󣬵������ǵش�Ҫ
�壬ʮ����Ҫ���������ǵĿ��̴���Ƶ��������������½�ͽ
���ֱײ����ץ�ˣ�����ھ��ܣ�ȴ˿��û���ٸ��������
LONG);

    	set("exits", ([
        	"east" : __DIR__"road3",
        	"west" : __DIR__"road2",
    	]));
        set("objects", ([
                "/d/beijing/npc/girl2" : 1,
                "/d/beijing/npc/kid1" : 1,
                CLASS_D("riyue") + "/qin" : 1,
                __DIR__"npc/dizi7" : 4,
        ]));
    	set("outdoors", "heimuya");
    	set("no_clean_up", 0);
    	setup();
    	replace_program(ROOM);
}
