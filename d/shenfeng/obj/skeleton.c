inherit ITEM;

void create()
{
	set_name("��Ǭ�ĺ���", ({ "Skeleton", "skeleton", "����" }));
        set_weight(500);
        if (clonep())
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
                set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
        	set("value", 1);
        	set("no_get", "�ⶫ��һ����ɢ�����Ǳ��ɣ�\n");
    	}
}
