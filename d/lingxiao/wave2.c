inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG 
��������һ��������������������������Ȼ����͸�����ڿ�
�����������Ⱥɽ��ԭ���������ǽ���������ϵı��㣬�¹���
���������յ��������ԣ������������������𡮱��������β��ɣ�
������ˮҹ���ᡯ���⾳��
LONG);
        set("exits", ([
            	"enter" : __DIR__"wave", 
            	"east"  : __DIR__"wave1", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

