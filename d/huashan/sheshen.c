inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס�
�粻С�ģ�һʧ�����ȥ��ֻ������ͷ���Ҳ�����
LONG);
        set("exits", ([
            	"eastdown" : __DIR__"canglong",
        ]));
        setup();
        replace_program(ROOM);
}
