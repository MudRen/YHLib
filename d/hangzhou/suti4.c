inherit ROOM;

void create()
{
        set("short", "�յ�");
        set("long", @LONG
����������������ϣ�������ɴ��ȸ����һƬ��������
�̴�������Ϊ����ʮ��֮�ף���Ȼ�����鴫��������ѹ������
������ɽ�š�����һƬ÷�֣��ֺ��ƺ�����Ժ�䣬���������С�
LONG);
        set("exits", ([
            	"north" : __DIR__"suti3",
            	"south" : __DIR__"suti5",
        ]));
        set("objects", ([
            	__DIR__"npc/liyuanzhi" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
