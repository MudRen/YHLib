inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
ÿ������վ�����ϣ��غ������ڷ���ҡҷ����˷��գ���
ݺ��֦ͷӭ����Ϸ��������ת���ʵ�����������ݺ����
LONG);
        set("exits", ([
            	"southwest" : __DIR__"jujingyuan",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
