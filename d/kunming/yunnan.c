inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ƹ��ԭ��������Ϊ�˺�ɫ��������ø����£�����
��ȥ��ֻ����Χ�������ԭʼɭ�ֲ����߼ʣ����ʱ�����ĸ�
־Զ��һ�ɺ���ӿ����������Ҫ��һ������ҵ��
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "southwest" : __DIR__"yunnan1", 
                "north"  : __DIR__"road7",
        ]));
        setup();
        replace_program(ROOM);
}
