inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
����һ����ʯ�����С�����������ػ�ת��������ͨ��ƽ
���ݡ���˵ǰ��������Ұ�޳�û�����ɾ�����������Զ��һ��
��������Ϊ���ɡ�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"west" : __DIR__"road1",
            	"east" : __DIR__"tianroad2",
        ]));
        setup();
        replace_program(ROOM);
}
