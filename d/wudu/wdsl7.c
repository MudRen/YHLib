inherit ROOM;

void create()
{
        set("short", "�嶾ɽ·");
        set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž���
����������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦��Ȼ
һ�������˻�ȥ����Ȼ��һ�����ƿ�֦�Ķ��ߡ�ǰ���ֳ�һ�����ߺ�
ǽ������������լԺ�� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"damen",
                "west" : __DIR__"wdsl6",
        ]));

        setup();
        replace_program(ROOM);
}
