inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ƽ����������������������̫ʦ�Σ�ǽ�Ϲ���һ��
�ֻ������õļ���ࡣ����յ�����û��һ���ˣ�����ƽ��
��ƽʱ���������ֻ�м������˲�ʱ����ɨһ�¡�
LONG);
        set("exits", ([
                "south"    :__DIR__"wangfu1",
        ]));

        setup();
        replace_program(ROOM);         
}
