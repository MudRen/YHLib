inherit ROOM;

void create()
{
        set("short", "�ù�̨");
        set("long", @LONG
�����ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɶ�
���޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������
Ŀ�����ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ��
���ڽ𶥣���̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ
�����𶥶�������ǰ�����������г�������֮�⡣
LONG);
        set("objects", ([
                CLASS_D("emei") + "/bei" : 1,
        ]));
        set("outdoors", "emei");
        set("exits", ([
                "northeast" : __DIR__"huacangan",
                "northwest" : __DIR__"woyunan",
                "south" : __DIR__"dgtsheshenya", 
        ]));
        setup();
        replace_program(ROOM);
}
