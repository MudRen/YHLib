inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
����һ����ʯ�����С�����������ػ�ת��������ͨ��ƽ
���ݡ���˵ǰ��������Ұ�޳�û�����ɾ������Ϸ���Զ��һ��
��������Ϊ���ɡ�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"south" : __DIR__"tiangate",
            	"west" : __DIR__"tianroad1",
        ]));
        setup();
        replace_program(ROOM);
}
