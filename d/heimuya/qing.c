inherit ROOM;

void create()
{
        set("short", "�����ô���");
        set("long", @LONG
���������������µ������������õĴ�����������ש��
�أ�����ȼ��Ѭ�㣬�ǳ��Ŀ���������������һ����һλ��
�߾��У������㱡�
LONG );
        set("exits", ([
            	"north" : __DIR__"chlang2",
        ]));
        set("objects",([
                CLASS_D("riyue") + "/jia" : 1,
            	__DIR__"npc/dizi5" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
