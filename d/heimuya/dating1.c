inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������µ�һ���÷����õĴ����������ڷǳ��Ŀ�
����������Ŀ��ȥ�������صģ���������һ�����ӡ�
LONG);
        
        set("exits", ([
            	"south" : __DIR__"grass2",
            	"north" : __DIR__"fenggate",
        ]));
        set("objects",([
            	__DIR__"npc/dizi3" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
