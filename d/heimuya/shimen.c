inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�õ�һ����ʯ��ǰ��ֻ�����Կ������д��֣������ǡ���
����¡��������ǡ�����Ӣ����������Ͽ��š����¹�������
������֡�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"eastdown" : __DIR__"shijie2",
            	"westup"   : __DIR__"up1",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/zhao" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
