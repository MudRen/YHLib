
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��λ�����ɽ��´��С�¡���Ժ�е�һ�ڹž�����
Ϊ��������Ϊÿ���峿������һ�ɾ޴�������Ծ�������
���𣬲����ο����ˣ�����Ϊ��һ�۴��澰����������һ����
᫵�ɽ����������һ����ɭɭ��С����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southup"     : __DIR__"shanlu7",
        ]));

        setup();
        replace_program(ROOM);
}
