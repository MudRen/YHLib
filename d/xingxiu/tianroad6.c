inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���塣����������Χ��ȥ�����׶���ԭ�ķ��
�����۵ס�����һ��С·������ɽ��ɽ����������Ϊǿ������
���޷�վ����
LONG);
        set("exits", ([
            	"eastdown" : __DIR__"tianroad5",
        ]));
        set("outdoors", "xingxiu");
        setup();
}
