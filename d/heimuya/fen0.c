inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������������̽��µ�һ���á�������Ŀ�²�Զ������
��һ��������ͯ���ܰ��ƴ��á�����վ���˷����õĵ��ӣ���
���ע������Χ��һ�С�
LONG);
        set("exits", ([
            	"north" :  __DIR__"grass1",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/tong" : 1,
            	__DIR__ "npc/dizi3" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
