inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ��ɽ�ȣ�������ֲ�Ų�ƺ�����治Զ����������
�̵������á�������һ����ɽ��ʯ����
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"east" : __DIR__"linjxd5",
            	"southup" : __DIR__"qinggate",
            	"west" : __DIR__"shidao1",
        ]));
        set("objects",([
            	__DIR__"npc/kid" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
